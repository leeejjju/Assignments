#lang plai
; <FunDef> ::= {deffun {<id> <id>} <F1WAE>}
; <F1WAE> ::= <num>
;            | { + <F1WAE> <F1WAE>}
;            | { - <F1WAE> <F1WAE>}
;            | { * <F1WAE> <F1WAE>}
;            | { with {<id> <F1WAE>} <F1WAE>}
;            | <id>
;            | { <id> <F1WAE>}


(define-type F1WAE
  [num (n number?)]
  [add (lhs F1WAE?) (rhs F1WAE?)]
  [sub (lhs F1WAE?) (rhs F1WAE?)]
  [with (name symbol?) (named-expr F1WAE?) (body F1WAE?)]
  [id (name symbol?)]
  [app (fun-name symbol?) (arg F1WAE?)])

(define-type FunDef
  [fundef (fun-name symbol?)
          (arg-name symbol?)
          (body F1WAE?)])

(define-type DefrdSub
  [mtSub]
  [aSub (name symbol?) (value number?) (ds DefrdSub?)])

;[contract] : symbol listof(FunDef) -> FunDef
; [purpose] : 
;   [tests] :
(define (lookup-fundef fun-name fundefs)
  (cond
    [(empty? fundefs) (error fun-name "funtion not found")]
    [else (if (symbol=? fun-name (fundef-fun-name (first fundefs)))
              (first fundefs)
              (lookup-fundef fun-name (rest fundefs)))]))

;[contract] : symbol DefrdSub -> F1WAE
; [purpose] : 
;   [tests] :
(define (lookup name ds)
  (type-case DefrdSub ds
    [mtSub () (error 'lookup "no binding for identifier")]
    [aSub (bound-name bound-value rest-ds)
          (if (symbol=? bound-name name)
              bound-value
              (lookup name rest-ds))]))

;[contract] : (concrete syntax) -> F1WAE
; [purpose] : 
;   [tests] :
(define (parse expr)
  (match expr
    [(? number?)                 (num expr)]
    [(list '+ l r)               (add (parse l) (parse r))]
    [(list '- l r)               (sub (parse l) (parse r))]
    [(list 'with (list i v) e)   (with i (parse v) (parse e))]
    [(? symbol?)                 (id expr)]
    [(list f a)                  (app f (parse a))]
    [else                        (error 'parse "bad syntax: ~a" expr)]))

;[contract] : F1WAE listof(fundef) DefrdSub -> number
; [purpose] :
;   [tests] :
(define (interp expr fun-defs ds)
  (type-case F1WAE expr
    [num (n) n]
    [add (l r) (+ (interp l fun-defs ds) (interp r fun-defs ds))]
    [sub (l r) (- (interp l fun-defs ds) (interp r fun-defs ds))]
    [with (bound-id named-expr bound-body)
          (interp bound-body
                  fun-defs
                  (aSub bound-id
                        (interp named-expr
                                fun-defs
                                ds)
                        ds))]
    [id (v) (lookup v ds)]
    [app (fun-name arg-expr)
         (local ([define the-fun-def (lookup-fundef fun-name fun-defs)])
           (interp (fundef-arg-name the-fun-def)
                   (interp arg-expr fun-defs ds)
                   (mtSub)))]))
;;For desugar 
(define-type F1WAES
  [numS  (n number?)]
  [addS  (lhs F1WAES?) (rhs F1WAES?)]
  [subS  (lhs F1WAES?) (rhs F1WAES?)]
  [mulS  (lhs F1WAES?) (rhs F1WAES?)]
  [withS (name symbol?) (named-expr F1WAES?) (body F1WAES?)]
  [idS   (name symbol?)]
  [appS  (fun-name symbol?) (arg F1WAES?)])

;[contract] : (concrete syntax) -> F1WAES
; [purpose] :
;   [tests] :
(define (parseS expr)
  (match expr
    [(? number?)                 (numS expr)]
    [(list '+ l r)               (addS (parseS l) (parseS r))]
    [(list '- l r)               (subS (parseS l) (parseS r))]
    [(list '* l r)               (mulS (parseS l) (parseS r))]
    [(list 'with (list i v) e)   (withS i (parseS v) (parseS e))]
    [(? symbol?)                 (idS expr)]
    [(list f a)                  (appS f (parseS a))]
    [else                        (error 'parseS "bad syntax: ~a" expr)]))

;(test (parseS '(* (+ 1 2) -2)) (mulS (subS 0 -1) -2 0))

;[contract] : F1WAES -> F1WAE
; [purpose] :
;   [tests] :
(define (desugar expr)
  (type-case F1WAES expr
    [numS (n)   (num n)]
    [addS (l r) (add (desugar l) (desugar r))]
    [subS (l r) (sub (desugar l) (desugar r))]
    [mulS (l r) (cond
                  [(= (interp (desugar l)  '() (mtSub) ) 0) (add (num 0) (num 0))]
                  [else
                   (cond
                     [(> (interp (desugar l) '() (mtSub)) 0) (add (desugar r)               (desugar (mulS (numS (- (interp (desugar l) '() (mtSub)) 1)) r)))]
                     [else                      (add (sub (num 0) (desugar r)) (desugar (mulS (numS (+ (interp (desugar l) '() (mtSub)) 1)) r)))])])]
    [withS (i v e) (with i (desugar v) (desugar e))]
    [idS   (i)     (id i)]
    [appS  (f a)   (app f (desugar a))]))
                    
                    
(test (interp (desugar (parseS '(* -4 -3))) '() (mtSub))  12)
(test (interp (desugar (parseS '(* -4 3)))  '() (mtSub)) -12)
(test (interp (desugar (parseS '(* 4 -3)))  '() (mtSub)) -12)
(test (interp (desugar (parseS '(* 4 3)))   '() (mtSub))  12)
(test (interp (desugar (parseS '(* (* 2 2) (* 1 -3)))) '() (mtSub)) -12)
;(test (interp (desugar (parseS '(* -4 -3))) '() (mtSub)) 2)

;(test (interp (parse '(+ 3 5)) '() (mtSub)) 8)