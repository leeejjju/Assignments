#5주차 퀴즈1
#22100579 이진주 
#3

num1 = int(input("첫번째 양의 정수를 입력하세요 :"))
num2 = int(input("두번째 양의 정수를 입력하세요 :"))
sum = 0
num = 0

if num1 < 0 or num2 < 0 :
    print("양의 정수가 아니라서 입력 에러입니다.")
elif num1 == num2 :
    print("입력 에러입니다. ")
else :
    if num1 > num2 : #num1이 클 경우(역순)
  
        for i in range (num1, num2 - 1, -1) :
            if i%2 == 0 :
                print(i, end='')
                if i != num2 :
                    print('-',end='')
                sum = sum + i 
            else :
                print(i, end='')
                if i != num2 :
                    print('+',end='')
                sum = sum - i
                
    else : #num2가 클 경우(정순) 

        for i in range (num1, num2+1, 1) :
            if i%2 == 0 :
                print(i, end='')
                if i != num2 :
                    print('-',end='')
                sum = sum + i
            else :
                print(i, end='')
                if i != num2 :
                    print('+',end='')
                sum = sum - i




    print('=', sum)
