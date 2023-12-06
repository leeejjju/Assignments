#lang plai
; HW2 due 10.10 Tue
; 22100579 JinjuLee

; 1. Implement F1WAE with deferred substitution.
; <F1WAE> ::= <num>
; 			| {+ <F1WAE> <F1WAE>}
; 			| {- <F1WAE> <F1WAE>}
;       | {* <F1WAE> <F1WAE>}
; 			| {with {<id> <F1WAE>} <F1WAE>}
; 			| <id>
; 			| {<id> <F1WAE>}


;; abstract
(define-type F1WAE
  [num (n number?)] ; for number
  [add (lhs F1WAE?) (rhs F1WAE?)] ; add
  [sub (lhs F1WAE?) (rhs F1WAE?)] ; sub 
  [mul (lhs F1WAE?) (rhs F1WAE?)] ; mul
  [with (name symbol?) (named-expr F1WAE?) (body F1WAE?)] ; variable binding
  [id (name symbol?)] ; name of variabl
  [app (fun-name symbol?) (arg F1WAE?)]) ;name of function

; function abstract
(define-type FunDef
  [fundef (fun-name symbol?) ; name of function
          (arg-name symbol?) ; name of parameter of function
          (body F1WAE?)]) ; body of funtion

; data abstract, for deferred substitution
(define-type DefrdSub
  [mtSub] ; empty one for no substitution
  [aSub (name symbol?) (value number?) (ds DefrdSub?)]) ; substitute name to value, ds is next one(if no need, use mtSub)


;; interpreter
; [contract] lookup-fundef : symbol listof(FunDef) −→ FunDef
; [purpose] find the funtion in funcdefs list with fun-name recursively
; [test] 
(define (lookup-fundef fun-name fundefs)
  (cond
    [(empty? fundefs) (error fun-name "function not found")] ; if not found
    [else (if (symbol=? fun-name (fundef-fun-name (first fundefs))) 
              (first fundefs) ; if it is, return it
              (lookup-fundef fun-name (rest fundefs)))])) ; if its not, lookup next element

; (define fun_list 
;       (list 
;           (fundef 'fun_1 'x (+ 'x 'x)) 
;           (fundef 'fun_2 'x 'y (+ 'x 'y)) 
;           (fundef 'fun_3 'x (- 100 'x))))

; (lookup-fundef 'fun_1 fun_list)


; [contract] lookup : symbol DefrdSub → F1WAE
; [purpose] find the value of the variable in ds with the name recursively
; [test]
(define (lookup name ds)
  (type-case DefrdSub ds
    [mtSub () (error 'lookup "no binding for identifier")] ; if not found
    [aSub (bound-name bound-value rest-ds) 
          (if (symbol=? bound-name name) ; find in ds recursively 
              bound-value 
              (lookup name rest-ds))]))

; [contract] interp : F1WAE listof(fundef) DefrdSub → number
; [purpose] for the expression of F1WAE expr, return the appropriate valule from fun-defs or ds
; [test]
(define (interp expr fun-defs ds) 
  (type-case F1WAE expr
    [num (n) n] ; return just number 
    [add (l r) (+ (interp l fun-defs ds) (interp r fun-defs ds))] ; return the value added
    [sub (l r) (- (interp l fun-defs ds) (interp r fun-defs ds))] ; return the value subtracted 
    [with (bound-id named-expr bound-body) ; call the interp again with aSub
          (interp bound-body 
                  fun-defs 
                  (aSub bound-id ; replace bound-id to interpreted named-expr
                        (interp named-expr fun-defs ds) ds))]
    [id   (v) (lookup v ds)] ; infd value of variabl using lookup 
    [app  (fun-name arg-expr) ; applicate the function using lookup-fundef
          (local ([define the-fun-def (lookup-fundef fun-name fun-defs)]) ; find the actual function using lookup-fundef and define it in here
                  (interp (fundef-body the-fun-def) ; interprete the body of function with...
                          fun-defs
                          (aSub (fundef-arg-name the-fun-def) ; replace the arg-name of the-fun-def as
                                (interp arg-expr fun-defs ds) ; result of interpreted arg-expr(input)
                                (mtSub))))]
    [else (error 'interp "too sweet to me! -> ~a" expr)]
))

; (test (interp (parse '(+ 1 3)) empty (mtSub)) 4)
; (test (interp (parse '(* 2 3)) empty (mtSub)) 6)
; (test (interp (parse '(* -2 -3)) empty (mtSub)) 6)
; (test (interp (parse '(* -2 3)) empty (mtSub)) -6)
; (test (interp (parse '(* 2 -3)) empty (mtSub)) -6)



; 2. Update the language to support multiplication by applying syntactic sugar and desugaring. 
; You must define the `desugar' function. 
; UPDATE: For your implementation, only consider multiplication with two integer values. You do not need to consider multiplication with an id and an integer (but if you can, it is great)

; [contract] desugar: sexp -> sexp
; [purpose] parse mul expression to desugaring expression consist of others
; [test]    (test (desugar (mul (num 2) (num 3))) (add (num 3) (add (num 3) (num 0))))
;           (test (desugar (mul (num -2) (num 10))) (add (num -10) (add (num -10) (num 0))))
;           (test (desugar (mul (num 3) (num -2))) (add (num -2) (add (num -2) (add (num -2) (num 0)))))

(define (desugar sexp) 
  (type-case F1WAE sexp
   [mul (l r) 
      (cond 
        [(= (interp l empty (mtSub)) 0) (num 0)]
        [(> (interp l empty (mtSub)) 0)  (add r (desugar (mul (num (interp(sub l (num 1)) empty (mtSub))) r)))]
        [else (add (num (interp (sub (num 0) r) empty (mtSub))) (desugar (mul (num (interp (add l (num 1)) empty (mtSub))) r)))])
        
    ]
   [else sexp])
)

(test (desugar (mul (num 2) (num 3))) (add (num 3) (add (num 3) (num 0))))
(test (desugar (mul (num -2) (num 10))) (add (num -10) (add (num -10) (num 0))))
(test (desugar (mul (num 3) (num -2))) (add (num -2) (add (num -2) (add (num -2) (num 0)))))

;; parser
; [contract] parse-fd: sexp -> FunDef
; [purpose] parse the expression to fundef
; [test] 
(define (parse-fd sexp)
  (match sexp
    [(list 'deffun (list f x) b)  (fundef f x (parse b))]))

; [contract] parse : sexp -> F1WAE
; [purpose] parse expression to F1WAE abstract form. (using desugar func for mul case)
; [test]    (test (parse'(+ 10 5)) (add (num 10) (num 5)))
;           (test (parse '(* 3 2)) (add (num 2) (add (num 2) (add (num 2) (num 0)))))
;           (test (parse '(with (x 10) (- x 3))) (with 'x (num 10) (sub (id 'x) (num 3))))


(define (parse sexp)
  (match sexp
    [(? number?)                (num sexp)]
    [(list '+ l r)              (add (parse l) (parse r))]
    [(list '- l r)              (sub (parse l) (parse r))]
    [(list '* l r)              (desugar (mul (parse l) (parse r)))]
    [(list 'with (list i v) e)  (with i (parse v) (parse e))]
    [(? symbol?)                (id sexp)]
    [(list f a)                 (app f (parse a))]
    [else                       (error 'parse "Bad syntax: ~a" sexp)]))

(test (parse'(+ 10 5)) (add (num 10) (num 5)))
(test (parse '(* 3 2)) (add (num 2) (add (num 2) (add (num 2) (num 0)))))
(test (parse '(with (x 10) (- x 3))) (with 'x (num 10) (sub (id 'x) (num 3))))

; 3. a. At the bottom of your code, put the following comments and put answers.
; Q1. Which scope is supported for a free identifier in a function call in your implementation, static scope, dynamic scope or both?

; Put the three test cases that show your answer for Q1 is correct. 
; (test ...) 
; This test case shows my implementation supports static scope.
; (test ...) 
; This test case shows my implementation does not support dynamic scope;  
; (test ...) 
; This test case shows my implementation supports dynamic scope;

; these are just examples. Depending on your answer for Q1, test cases vary.
