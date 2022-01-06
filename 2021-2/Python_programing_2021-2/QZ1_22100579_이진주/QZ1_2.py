#5주차 퀴즈1
#22100579 이진주 
#2

num = int(input("양의 정수를 입력해주세요 : "))
sum = 1


if num < 0 :
    print("계산할 수 없는 값입니다. ")
else :
    for i in range(num, 0, -1) : #각각의 팩토리얼 값 
        for j in range(1, i+1) : #팩토리얼 계산 
            sum = sum * j 
        print(sum, end='' ) #방금 계산한 팩토리얼 값 출력
        if i != 1 :
            print(', ', end='')
        sum = 1 #sum 초기화 
              

    
