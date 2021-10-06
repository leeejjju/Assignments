#1. 구구단 출력 2단~19단

for dan in range(2, 20) :
    for i in range(1, 10) :
        print(dan, 'x', i, '=', dan*i)
        i = i + 1
    dan = dan + 1
    print("")


#2. 리스트 속 아이템의 모음 갯수 출력하기

word = ['Apple', 'box', 'buzz', 'CANTUS', 'dish', 'knife', 'lady', 'pitch', 'stimulus', 'wish', 'wolf' ]

moum = [ 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' ]
num = 0 #모음갯수


for i in range(len(word)) :
    

    print(word[i],',', end='')
    for j in range(len(moum)) :
        if moum[j] in word[i] :
            print(moum[j], ' ', end='')
            num += 1
            j += 1

    print('로 모음 ', num,'개')
    i += 1
    num = 0 



        

    
