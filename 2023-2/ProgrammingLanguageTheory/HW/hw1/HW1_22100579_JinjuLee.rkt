#lang plai

; HW1 due 9.8 Fri
; The number of problems solved by myself: ###### out of 8


; Problem 1:
; Solved by myself: Y
; Time taken: about 5 min
; [contract] dollar->won : number -> number
; [purpose] To convert dollar to won, using that 1 dollar is 1324 won
; [tests]   (test (dollar->won 1) 1324)
;           (test (dollar->won 2) 2648)
(define (dollar->won d) (* d 1324))
'test1======================================
(test (dollar->won 1) 1324)
(test (dollar->won 2) 2648)


; Problem 2:
; Solved by myself: Y
; Time taken: about 10 min

; [contract] my_max : number number -> number
; [purpose] To find the larger value of two
; [tests]   (test (my_max 1 3) 3)
;           (test (my_max 107 128) 128)
(define (my_max a b) 
    (cond 
        [(> a b) a] 
        [(<= a b) b]))

; [contract] max-of-three-integers : number number number -> number
; [purpose] To find the maximum value among the inputs 
; [tests]   (test (max-of-three-integers 1 2 3) 3)
;           (test (max-of-three-integers 107 128 59) 128)
(define (max-of-three-integers a b c) (my_max a (my_max b c)))
'test2======================================
(test (max-of-three-integers 1 2 3) 3)
(test (max-of-three-integers 107 128 59) 128)




; Problem 3:
; Solved by myself: Y
; Time taken: about 5 min
; [contract] volume-cuboid : number number number -> number
; [purpose] To find the maximum value among the inputs 
; [tests]   (test (volume-cuboid 1 2 3) 3)
;           (test (volume-cuboid 107 128 59) 128)
(define (volume-cuboid l b h) (* l (* b h)))
'test3======================================
(test (volume-cuboid 1 2 3) 6)
(test (volume-cuboid 2 5 10) 100)



; Problem 4:
; Solved by myself: N (I didnt know what is gcd and formula of it, so i find this ref: https://myjamong.tistory.com/138)
; Time taken: about 15 min
; [contract] gcd : number number -> number
; [purpose] To find the greatest common divisor of the two inputs 
; [tests]   (test (gcd 6 3) 3)
;           (test (gcd 12 16) 4)
(define (gcd a b) 
    (cond
        [(and (> a b) (= (remainder a b) 0)) b]
        [(and (<= a b) (= (remainder b a) 0)) a]
        [(and (> a b)) (gcd b (remainder a b))]
        [(and (<= a b)) (gcd a (remainder b a))]))

'test4======================================
(test (gcd 6 3) 3)
(test (gcd 12 16) 4)


; Problem 5:
; Solved by myself: half Y (I needed to remember the formula of factorial, so I find this ref: https://coding-factory.tistory.com/606)
; Time taken: about 15 min

; [contract] factorial : number -> number
; [purpose] To find the factorial value of input n
; [tests]   (test (factorial 4) 24)
;           (test (factorial 5) 120)
(define (factorial n) 
    (cond
        [(= n 1) 1]
        [else (* n (factorial (- n 1)))]))

; [contract] combination : number number -> number
; [purpose] To find the nummber of possible combination that can be there 
; [tests]   (test (combination 1 2 3) 3)
;           (test (combination 107 128 59) 128)
(define (combination n k) (/ (factorial n) (* (factorial (- n k)) (factorial k))))
'test5======================================
(test (combination 5 3) 10)
(test (combination 8 2) 28)



; Problem 6:
; Solved by myself: Y
; Time taken: about 20 min

(define-type Vehicle
    [Bicycle    (wheels number?)]
    [Car        (wheels number?)
                (windows number?)]
    [Airplane   (wheels number?)
                (windows number?)
                (engines number?)])

'test6======================================
(define my_bike (Bicycle 2))
(define my_car (Car 3 4))

; [contract] vehicle-tax : Vehicle -> number
; [purpose] To calculate the total tax of input instance
; [tests]   (test (vehicle-tax my_bike) 2)
;           (test (vehicle-tax my_car) 7)
(define (vehicle-tax v) 
    (cond
        [(Bicycle? v) (Bicycle-wheels v)]
        [(Car? v) (+ (Car-wheels v) (Car-windows v))]
        [(Airplane? v) (+ (Airplane-wheels v) (+ (Airplane-windows v) (Airplane-engines v)))]))
(test (vehicle-tax my_bike) 2)
(test (vehicle-tax my_car) 7)

; [contract] is-vehicle-safe : Vehicle -> string
; [purpose] To check if the input vehicle is safe or not 
; [tests]   (test (is-vehicle-safe my_bike) "safe")
;           (test (is-vehicle-safe my_car) "unsafe")
(define (is-vehicle-safe v) 
    (cond
        [(and (Bicycle? v) (< (Bicycle-wheels v) 4)) "safe"]
        [(and (Car? v) (and (> (Car-wheels v) 3) (> (Car-windows v) 2))) "safe"]
        [(and (Airplane? v) (and (> (Airplane-wheels v) 2) (and (> (Airplane-windows v) 10) (> (Airplane-engines v) 1)))) "safe"]
        [else "unsafe"]))

(test (is-vehicle-safe my_bike) "safe")
(test (is-vehicle-safe my_car) "unsafe")


; Problem 7:
; Solved by myself: half Y (at first, I sufferd with finding the way how to implement the function basicly, and my friend Eunhyuk gave me the clue(concept to use function in list or something)) 
; Time taken: about 30 min


; [contract] parse-alphabet : symbol -> symbol
; [purpose] To convert the input to corresponding character
;           'a with 'alice, 'c with 'cherry, 'j with 'jc, 'k with 'kate and keeps /other characters as unnamed
; [tests]   (test (parse-alphabet 'a) 'apice)
;           (test (parse-alphabet 'x) unnamed)
(define (parse-alphabet c) 
    (cond
        [(symbol=? c 'a) 'alice]
        [(symbol=? c 'c) 'cherry]
        [(symbol=? c 'j) 'jc]
        [(symbol=? c 'k) 'kate]
        [else 'unnamed]))

; [contract] name-alphabet : list -> list
; [purpose] To produces a corresponding list of an alphabetical character with names starting with the alphabet character
;           'a with 'alice, 'c with 'cherry, 'j with 'jc, 'k with 'kate and keeps /other characters as unnamed
; [tests]   (test (name-alphabet list_one) list('alice 'cherry 'jc))
;           (test (name-alphabet list_two) list(unnamed unnamed 'kate))
(define (name-alphabet l) 
    (cond
        [(empty? l) empty]
        [else (append (cons (parse-alphabet(first l)) empty) (name-alphabet(rest l)))]))


(define list_one (list 'a 'c 'j))
(define list_two (list 'x 'y 'k))
'test7======================================
(test (name-alphabet list_one) '(alice cherry jc))
(test (name-alphabet list_two) '(unnamed unnamed kate))


; hw: https://docs.google.com/document/d/1Z_CoXtEdAmjo6UuKxMNWLoOTpXtFNpzhN0V4xXSq8Tk/edit
; whole:  https://docs.google.com/document/d/1bCZSaLvSdgT7AzHtlQdaxnQuVwgAw7ylmtUd-OBT6wk/edit
; my: https://docs.google.com/document/d/1_BPOPu76ClWqP-Yf6pJVH8YoRIyLoFoswRD-FbN6OBE/edit

;TODO 
; Problem 8:
; Solved by myself: Y 
; Time taken: about 20 min

; [contract] change-symbol : symbol symbol symbol -> symbol
; [purpose] To return new symbol if s is same as old, and return s if not.
; [tests]   (test (change-symbol 'cherry 'cherry 'claire) 'claire)
;           (test (change-symbol 'jc 'alice 'apple) 'jc)
(define (change-symbol s old new) 
    (cond
        [(symbol=? s old) new]
        [else s]))


; [contract] update-name : symbol symbol list -> number
; [purpose] To find the factorial value of input n
; [tests]   (test (update-name 'cherry 'claire list_three) 24)
;           (test (update-name 5) 120)
(define (update-name old new l) 
    (cond
        [(empty? l) empty]
        [else (append (cons (change-symbol (first l) old new) empty) (update-name old new (rest l)))]))


(define list_three (list 'jc 'cherry 'kate))
(define list_four (list 'alice 'alice 'kate))
'test8======================================
(test (update-name 'cherry 'claire list_three) '(jc claire kate))
(test (update-name 'alice 'apple list_four) '(apple apple kate))


