#5주차 수업내 코딩
#1. 두개의 문자열을 입력받아 크기비교, 결과 출력(~는 ~보다 크다)

str1 = input("첫번째 문자열을 입력하세요 : ")
str2 = input("두번째 문자열을 입력하세요 : ")

if str1 > str2 :
    print(str1, '은(는)', str2, '보다 크다')
else :
    print(str2, '은(는)', str1, '보다 크다')


print("")

#2. 양의 정수를 입력받아 소수인지 아닌지 판별, 출력

num = int(input("양의 정수를 입력하세요 : "))
prime = True


for i in range(2, num) :
    if num % i == 0 : #2~자기자신-1까지의 수 중 나누어떨어진다면 
        prime = False #소수아님 
        break

if prime :
    print(num, '은 소수입니다.')
else :
    print(num, '은 소수가 아닙니다.')
