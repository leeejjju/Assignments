#HomeWork 15week1
#22100579이진주
'''
1.varFTs.py
다음의 기능을 하는 함수를 정의하고 2번씩 실행하시오

a)  def sorted(a, b, c, d)
a, b, c, d 4개 숫자가 정열되어 있으면 True, 그렇지 않으면 False를 리턴한다.
이때 오름차순, 내림차순 2가지 경우를 모두 확인한다.

>>> sorted(3, 0, -2, -5)
True

>>> sorted(3, 0, 3, 0)
False

>>> sorted(2, 8, 12, 16)
True'''

def sorted(a, b, c, d):
    if(a > b > c > d):
        print("True")
        return True
    if(a < b < c < d):
        print("True")
        return True

    print("False")
    return False

sorted(3, 0, -2, -5)
sorted(3, 0, 3, 0)
sorted(2, 8, 12, 16)

#--------------------------

'''b)  def numDigit(n)
파라미터 실수  n 의 정수 자리 수와 소수 이하 자리수를 출력한다.  

>>> numDigit(3.12)
정수 자리 수 1, 소수 자리 수 2

>>> numDigit(119.0)
정수 자리 수 3, 소수 자리 수 1

>>> numDigit(10.08217)
정수 자리 수 2, 소수 자리 수 5'''

print()

def numDigit(n):
    
    INT = int(n)
    countINT = 0

    while(1):
        countINT += 1
        if(INT<10):
            break
        INT = int(INT//10)

    FLOAT = str(n)
    countFLOAT = 0
    start = 0

    for i in FLOAT:
        if start == 1:
            countFLOAT +=1
        if i == '.':
            start = 1
    
    print("정수 자리 수", countINT ,"소수 자리 수", countFLOAT)



numDigit(3.12)
numDigit(119.0)
numDigit(10.08217)

