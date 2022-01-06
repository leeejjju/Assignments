#10주차 수업내코딩
#1.양의 정수 두개를 받아 그 사이에 있는 소수를 모두 찾아 리스트에 저장 후 출력.(두개의 수 포함.
#두 파라미터가 양의 정수가 아니면 에러메세지 출력후 종료

def prime_num(num):
    #각 값이 소수인지 아닌지 확인하는 함수. 소수이면 True, 아니면 False 리턴. 
    prime = True

    for i in range(2, num) :
        if num % i == 0 : #min~max까지의 수 중 나누어떨어진다면 
            prime = False #소수아님 
            break

    return prime

n1 = int(input("첫번째 양의 정수:"))
n2 = int(input("두번째 양의 정수:"))
list = []

if n1 <= 0 or n2 <= 0 :
    print("양의 정수가 아닙니다")
else:
    for i in range(min([n1,n2]), max([n1,n2])):
        if prime_num(i):
            list.append(i)

    list.append(max([n1,n2]))
    print("두 수와 그 사이의 소수 = ", list)  


#2.재귀함수로 코딩. 1!, 2!...n!값을 리스트로 만들어 return. math.factorial(n)을 활용. 

import math



'''def fact(n):
    if n == 0:
        return 1
    else:
        return n*fact(n-1)'''


def fact(n) :
    list = []
    for i in range(1, n+1) :
        list.append(math.factorial(i))
    return list 


print("1! ~5! = ", fact(5))
print("1! ~20! = ", fact(20))








    
