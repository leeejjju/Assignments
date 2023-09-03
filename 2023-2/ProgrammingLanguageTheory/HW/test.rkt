#lang racket/gui

(define my-language 'English)

(define translations
  #hash([Chinese . "你好 世界"]
        [English . "Hello world!"]
        [French . "Bonjour le monde"]
        [German . "Hallo Welt"]
        [Greek . "Γειά σου, κόσμε"]
        [Portuguese . "Olá mundo"]
        [Spanish . "Hola mundo"]
        [Thai . "สวัสดีชาวโลก"]
        [Turkish . "Merhaba Dünya"]))

(define my-hello-world
  (hash-ref translations my-language
            "안녕 세상 !"))

(message-box "" my-hello-world) 


; https://marketplace.visualstudio.com/items?itemName=evzen-wybitul.magic-racket 
; https://www.youtube.com/watch?v=sK6yET1k_9A&ab_channel=jestarray