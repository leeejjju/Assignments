#lang plai
; HW4 due 12.08 Fri
; 22100579 JinjuLee

; ref: https://docs.google.com/presentation/d/1l_OaH2OOtTmBttI8hs0ehjDfpmsnmDOEWHnlyClSBwk/edit#slide=id.g460e7c637b_1_69 
; <KCFAE> ::= <num>
;         | {+ <KCFAE> <KCFAE>}
;         | {- <KCFAE> <KCFAE>}
;         | <id>
;         | {fun {<id>} <KCFAE>}
;         | {if0 <KCFAE> <KCFAE> <KCFAE>}
;         | {withcc <id> <KCFAE>} 

; Task1
; Solved by myself: Y
; Time taken: about 2 hours

;; abstract
(define-type KCFAE
  [num      (n number?)]
  [add      (lhs KCFAE?) (rhs KCFAE?)]
  [sub      (lhs KCFAE?) (rhs KCFAE?)]
  [id       (name symbol?)]
  [fun      (param symbol?) (body KCFAE?)]
  [if0      (test KCFAE?) (t KCFAE?) (f KCFAE?)]
  [app      (fun-expr KCFAE?) (arg-expr KCFAE?)]
  [withcc   (cont-var symbol?) (body KCFAE?)])

(define-type KCFAE-Value
  [numV       (n number?)]
  [closureV   (p procedure?)]
  [contV      (c procedure?)])

(define-type DefrdSub
  [mtSub]
  [aSub   (name symbol?) (value KCFAE-Value?) 
          (ds DefrdSub?)])

; [contract]    lookup : symbol DefrdSub → KCFAE-Value
; [purpose]     find the value of the variable in ds with the name recursively
; [test]        (test (lookup 'x dss) (numV 10))
;               (test (lookup 'y dss) (numV 20))
;               (test (lookup 'z dss) (numV 30))
(define (lookup name ds)
    (type-case DefrdSub ds
        [mtSub () (error 'lookup "no binding for identifier")]
        [aSub (bound-name bound-value rest-ds)
                (if (symbol=? bound-name name)
                bound-value
                (lookup name rest-ds))]))

(define dss (aSub 'x (numV 10) (aSub 'y (numV 20) (aSub 'z (numV 30) (mtSub)))))
(test (lookup 'x dss) (numV 10))
(test (lookup 'y dss) (numV 20))
(test (lookup 'z dss) (numV 30))


; [contract] num+ : numV numV -→ numV
; [purpose] calcutate mongs numVs
; [test]    (test (num+ (numV 10) (numV 10)) (numV 20))
;           (test (num+ (numV 10) (numV 2)) (numV 12))
;           (test (num+ (numV 5) (numV 5)) (numV 10))
(define (num+ n1 n2)
  (numV (+ (numV-n n1) (numV-n n2))))

(test (num+ (numV 10) (numV 10)) (numV 20))
(test (num+ (numV 10) (numV 2)) (numV 12))
(test (num+ (numV 5) (numV 5)) (numV 10))


; [contract] num- : numV numV -> numV
; [purpose] calcutate mongs numVs
; [test]    (test (num- (numV 10) (numV 10)) (numV 0))
;           (test (num- (numV 10) (numV 2)) (numV 8))
;           (test (num- (numV 15) (numV 5)) (numV 10))
(define (num- n1 n2)
  (numV (- (numV-n n1) (numV-n n2))))

(test (num- (numV 10) (numV 10)) (numV 0))
(test (num- (numV 10) (numV 2)) (numV 8))
(test (num- (numV 15) (numV 5)) (numV 10))



;; parser
; [contract] parse : sexp -> KCFAE
; [purpose] parse expression to KCFAE abstract form.
; [test]    (test (parse '(+ 10 10)) (add (num 10) (num 10)))
;         (test (parse '(with (x 5) (+ x 2))) (app (fun 'x (add (id 'x) (num 2))) (num 5)))
;         (test (parse '(fun (x) (+ x x))) (fun 'x (add (id 'x) (id 'x))))
(define (parse sexp)
   (match sexp
        [(? number?)                (num sexp)]
        [(list '+ l r)              (add (parse l) (parse r))]
        [(list '- l r)              (sub (parse l) (parse r))]
        [(list 'with (list i v) e)  (app (fun i (parse e)) (parse v))]
        [(? symbol?)                (id sexp)]
        [(list 'fun (list p) b)     (fun p (parse b))]
        [(list f a)                 (app (parse f) (parse a))]
        [(list 'if0 test t f) (if0 (parse test) (parse t) (parse f))]
        [(list 'withcc cont-var body) (withcc cont-var (parse body))]
        [else                       (error 'parse "bad syntax: ~a" sexp)]))

(test (parse '(+ 10 10)) (add (num 10) (num 10)))
(test (parse '(with (x 5) (+ x 2))) (app (fun 'x (add (id 'x) (num 2))) (num 5)))
(test (parse '(fun (x) (+ x x))) (fun 'x (add (id 'x) (id 'x))))


;; interpreter
; [contract] interp: KCFAE DefrdSub (KCFAE-Value -> alpha) -> alpha
;         or interp: KCFAE DefrdSub receiver -> doesn't return (but receiver returns)
; [purpose] parse expression to KCFAE abstract form.
; [test]  (test (interp (parse '(with (y 10) (+ y y))) (mtSub) (lambda (x) x)) (numV 20))
;         (test (interp (app (fun 'x (add (id 'x) (num 5))) (num 10)) (mtSub) (lambda (result) result)) (numV 15))
;         (test (interp (parse '(if0 (- 10 10) 1 0)) (mtSub) (lambda (x) x)) (numV 0))
(define (interp kcfae ds k)
  (type-case KCFAE kcfae
    [num (n) (k (numV n))]
    [add (l r) (interp l ds
                  (lambda (lv) 
                    (interp r ds
                      (lambda (rv)
                      (k (num+ lv rv))))))]
    [sub (l r) (interp l ds
                  (lambda (lv) 
                    (interp r ds
                      (lambda (rv)
                      (k (num- lv rv))))))]
    [id (s) (k (lookup s ds))]
    [fun (p b) (k (closureV (lambda (a-val dyn-k)
                        (interp b (aSub p a-val ds) dyn-k))))]
    [if0 (test t f) (interp test ds
                  (lambda (tv) 
                    (if(eq? (interp test ds k) (numV 0))
                      (interp t ds k)
                      (interp f ds k))))]
    [app (f a) (interp f ds
                  (lambda (f-val) 
                    (interp a ds
                      (lambda (a-val)
                        (type-case KCFAE-Value f-val
                          [closureV (c) (c a-val k)]
                          [contV (c) (c a-val)]
                          [else (error "not an appllicable value")])))))]
    [withcc (cont-var body)
            (interp body
                (aSub cont-var
                  (contV (lambda (val)
                    (k val)))
                  ds)
                k)]
  ))
(test (interp (parse '(with (y 10) (+ y y))) (mtSub) (lambda (x) x)) (numV 20))
(test (interp (app (fun 'x (add (id 'x) (num 5))) (num 10)) (mtSub) (lambda (result) result)) (numV 15))
(test (interp (parse '(if0 (- 10 10) 1 0)) (mtSub) (lambda (x) x)) (numV 0))


; [contract] run : sexp -→ numV
; [purpose] run the sub expression with ds more convenient
; [test]    
(define (run sexp ds)
     (interp (parse sexp) ds (lambda (x) x)))
(test (run '(+ 10 10 ) (mtSub)) (numV 20))
(test (run '(with (x 5) (+ x 2)) (mtSub)) (numV 7))
(test (run '(if0 (- 10 10) 1 0) (mtSub)) (numV 0))


; unique test cases for show withcc
(test (run '(withcc k (+ 2 (k 3))) (mtSub)) (numV 3))
(test (run '(withcc k (withcc m (+ (k 2) (m 3)))) (mtSub)) (numV 2))
(test (run '(withcc k (if0 (k 5) 42 10)) (mtSub)) (numV 5))
(test (run '(withcc k (+ (+ (k 2) 5) 10)) (mtSub)) (numV 2))
(test (run '(withcc k (with (x 5) (+ x (k 10)))) (mtSub)) (numV 10))


