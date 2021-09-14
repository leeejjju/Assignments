#3주 수업내 코딩
# 2개의 정수를 입력받아 더한 결과와 나머지 값을 출력한다.
#나머지 연산은 큰값에서 작은 값을 나누도록 한다.

num1 = int (input("첫번째 숫자를 입력하세요"))
num2 = int (input("두번째 숫자를 입력하세요"))

sum = num1 + num2

if num1 > num2: 
    rest = num1 % num2
else: 
    rest = num2 % num1
print("더한 값은" ,sum)
print("나눈 값은", rest)

