#lang plai

;;abstract part

(define-type F1WAE
  [num (n number?)]
  [add (lhs F1WAE?) (rhs F1WAE?)]
  [sub (lhs F1WAE?) (rhs F1WAE?)]
  [with (name symbol?) (named-expr F1WAE?) (body F1WAE?)] [id (name symbol?)]
  [app (fun-name symbol?) (arg F1WAE?)])

(define-type FunDef
  [fundef (fun-name symbol?)
          (arg-name symbol?)
          (body F1WAE?)])

(define-type DefrdSub
  [mtSub]
  [aSub (name symbol?) (value number?) (ds DefrdSub?)])

;; F1WAE_S abstract syntax
(define-type F1WAE_S
  [num_s (n number?)]
  [add_s (lhs F1WAE_S?) (rhs F1WAE_S?)]
  [sub_s (lhs F1WAE_S?) (rhs F1WAE_S?)]
  [mul_s (lhs F1WAE_S?) (rhs F1WAE_S?)]
  [with_s (name symbol?) (named-expr F1WAE_S?) (body F1WAE_S?)]
  [id_s (name symbol?)]
  [app_s (fun-name symbol?) (arg F1WAE_S?)])


;; desugar : F1WAE_S -> F1WAE
(define (desugar expr)
  (type-case F1WAE_S expr
    [num_s (n) (num n)]
    [add_s (l r) (add (desugar l) (desugar r))]
    [sub_s (l r) (sub (desugar l) (desugar r))]
    [mul_s (l r)
           (let ([dl (desugar l)] [dr (desugar r)])
             (cond
               [(and (num? dl) (num? dr) (> (num-n dl) 1))
                (add dr (desugar (mul_s (num_s (small-interp (sub_s l (num_s 1)))) r)))]
               [(and (num? dl) (num? dr) (= (num-n dl) 1))
                dr]
               [else (num 0)]))]
    [with_s (bound-id named-expr bound-body)
     (with bound-id (desugar named-expr) (desugar bound-body))]
    [id_s (v) (id v)]
    [app_s (fun-name arg-expr) (app fun-name (desugar arg-expr))]))


;;parsing part


;; Parsing for F1WAE_S
(define (parse-s sexp)
  (cond
    [(number? sexp)               (num_s sexp)]
    [(and (list? sexp) 
          (equal? '+ (first sexp)))  (add_s (parse-s (second sexp)) (parse-s (third sexp)))]
    [(and (list? sexp) 
          (equal? '- (first sexp)))  (sub_s (parse-s (second sexp)) (parse-s (third sexp)))]
    [(and (list? sexp) 
          (equal? 'mul (first sexp))) (mul_s (parse-s (second sexp)) (parse-s (third sexp)))]
    [(and (list? sexp)
          (equal? 'with (first sexp)))
          (with_s (first (second sexp)) (parse-s (second (second sexp))) (parse-s (third sexp)))]
    [(symbol? sexp)               (id_s sexp)]
    [(and (list? sexp) 
          (symbol? (first sexp)))   (app_s (first sexp) (parse-s (second sexp)))]
    [else                        (error 'parse-s "bad syntax: ~a" sexp)]))


;; parse : sexp -> F1WAE
(define (parse sexp)
  (cond
    [(number? sexp)               (num sexp)]
    [(and (list? sexp) 
          (equal? '+ (first sexp)))  (add (parse (second sexp)) (parse (third sexp)))]
    [(and (list? sexp) 
          (equal? '- (first sexp)))  (sub (parse (second sexp)) (parse (third sexp)))]
    [(and (list? sexp)
          (equal? 'with (first sexp)))
          (with (first (second sexp)) (parse (second (second sexp))) (parse (third sexp)))]
    [(symbol? sexp)               (id sexp)]
    [(and (list? sexp) 
          (symbol? (first sexp)))   (app (first sexp) (parse (second sexp)))]
    [else                        (error 'parse "bad syntax: ~a" sexp)]))




;;interpret part

(define (small-interp expr)
  (type-case F1WAE_S expr
    [num_s (n) n]
    [sub_s (l r) (- (small-interp l) (small-interp r))]
    [else (error 'small-interp "Unsupported operation")]))






;; lookup-fundef : symbol listof(FunDef) -→ FunDef
(define (lookup-fundef fun-name fundefs)
  (cond
    [(empty? fundefs) (error fun-name "function not found")]
    [else (if (symbol=? fun-name (fundef-fun-name (first fundefs)))
              (first fundefs)
              (lookup-fundef fun-name (rest fundefs)))]))

;; lookup : symbol DefrdSub → F1WAE
(define (lookup name ds)
  (type-case DefrdSub ds
    [mtSub () (error 'lookup "no binding for identifier")]
    [aSub (bound-name bound-value rest-ds)
          (if (symbol=? bound-name name)
              bound-value
              (lookup name rest-ds))]))

;; interp : F1WAE listof(fundef) DefrdSub → number
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
           (interp (fundef-body the-fun-def )
                   fun-defs
                   (aSub (fundef-arg-name the-fun-def )
                         (interp arg-expr fun-defs ds)
                         (mtSub))))]))


(define fundefs-with-with
  (list (fundef 'sumWithFive 'z (with 'x (num 5) (add (id 'z) (id 'x))))))
(test (interp (app 'sumWithFive (num 10)) fundefs-with-with (mtSub)) 15)

(define multiple-fundefs
  (list (fundef 'multiplyByTwo 'm (add (id 'm) (id 'm)))
        (fundef 'subtractThree 's (sub (id 's) (num 3)))))

(interp (with 'a (app 'multiplyByTwo (num 4))
              (app 'subtractThree (id 'a)))
       multiple-fundefs
       (mtSub))
; 결과: 5
(define fundefs-calling-functions
  (list (fundef 'addFive 'w (add (id 'w) (num 5)))
        (fundef 'useAddFive 'u (app 'addFive (add (id 'u) (id 'u))))))

(interp (app 'useAddFive (num 3)) fundefs-calling-functions (mtSub))
; 결과: 11
(define fundefs-with-intermediate-calculation
  (list (fundef 'calculate 'c 
                (with 'doubleC (add (id 'c) (id 'c))
                      (sub (id 'doubleC) (num 3))))))

(interp (app 'calculate (num 7)) fundefs-with-intermediate-calculation (mtSub))
; 결과: 11

(define example1 (parse-s '(mul 3 4)))
(desugar example1) ; 이를 F1WAE로 디슈가링합니다.
(interp (desugar example1) '() (mtSub)) ; 결과는 12가 되어야 합니다.