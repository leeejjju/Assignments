#12주차 퀴즈2
#22100579 이진주 
#2

'''재귀함수 만들기.
factorial 값을 구하는 fact(n)을 작성하고 결과 출력.
단 n은 양의 정수이며 fact(1)은 1을 반환한다.'''

def fac(n) :
    if n == 1 :
        return 1
    else :
        return n*fac(n-1)

print("fac(5) = ", fac(5))
print("fac(3) = ", fac(3))
