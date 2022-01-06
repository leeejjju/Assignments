#HW2-1
#두 개의 정수를 입력 받아서, 두 정수를 포함하여 그 사이에 존재하는 정수들의 합을 계산하여 출력하는 프로그램을 작성하시오. 
#예를 들어서 -2과 3이 입력되면 -2 + -1 + 0 + 1 + 2 + 3 = 3 이라고 출력한다.


num1 = int(input("첫번째 정수를 입력하세요 : "))
num2 = int(input("두번째 정수를 입력하세요 : "))
sum = 0


if num1 > num2 : #역순 
    for i in range( num1, num2-1, -1) :
        print(i, end = '')
        if i != num2 :
                print(" + ", end='')
        sum = sum+i
            
else : #정순 
    for i in range( num1, num2+1, 1) :
        print(i, end = '')
        if i != num2 :
            print(" + ", end='')
        sum = sum+i

print(' = ', sum) #결과출력 
