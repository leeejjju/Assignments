#lang plai
(define-type AE
    [num (n number?)]
    [add (lhs AE?) (rhs AE?)]
    [sub (lhs AE?) (rhs AE?)])

;(+ 1 2)
(add (num 1) (num 2))
;(+ (- 2 3) 5)
(add (sub (num 2) (num 3)) (num 5))


(define ae1 (add (sub (num 3) (num 4)) (num 7)))
(sub? ae1) ;type checking

; retrieving expressions
; (add-rhs ae1)
; (add-lhs ae1)
; (sub-rhs (add-lhs ae1))

; parse: sexp -> AE
; to convert sexp into AEs in abstract syntax
(define (parse sexp) 
    (cond
        [(number? sexp) (num sexp)]
        [(and (eq? (first sexp) '+) (= 3 (length sexp))) (add (parse (second sexp)) 
                                    (parse (third sexp)))]
        [(and (eq? (first sexp) '-)  (= 3 (length sexp))) (sub (parse (second sexp)) 
                                    (parse (third sexp)))]
        [else (error 'parse "bad syntax: ~a" sexp)]))

;; test
(test (parse '3) (num 3))
(test (parse '{+ 3 4}) (add (num 3) (num 4)))
(test (parse '{+ { - 5 4} 5}) (add (sub (num 5) (num 4)) (num 5)))
(test/exn (parse '{- 5 1 2}) "parse: bad syntax: (- 5 1 2)")


; interp: AE -> number
; compute the result number from AE 
(define (interp an-ae) 
    (type-case AE an-ae
        [num (n) n]
        [add (l r) ( + (interp l) (interp r))]
        [sub (l r) ( - (interp l) (interp r))]))

(test (interp (parse '5)) 5)
(test (interp (parse (+ 1 2))) (+ 1 2))
(test (interp (parse (- (- 6 5) (+ 4 (- 5 1))))) (- (- 6 5) (+ 4 (- 5 1))))


