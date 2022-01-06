#12주차 퀴즈2
#22100579 이진주 
#3
'''숫자 맞추기 게임.
dice() 1-10까지 숫자중 하나를 랜덤 생성
위를 세번 실행해 만든 값 a b c에 대해 a,c값과 (a+b)*c 결과값을 출력하고
2번째 숫자 b값을 맞추는 게임을 코딩한다.
맞으면 맞았다고 출력, 틀리면 기회 세번 주고 못맞주면
"정답을 찾지 못하고 종료. b는 x입니다" 라고 출력한다.'''
import random

def dice() :
    num = random.sample(range(1, 10), 1)
    result = int(num[0])
    return result

a = dice()
b = dice()
c = dice()
count = 0
good = 0


print("a =", a, "c =", c, "(a+b)*c =", (a+b)*c)


while(count < 3) :
    
    answer = int(input("b 값을 입력하세요 :"))
    
    if(answer == b):
        print("정답입니다!")
        good = 1
        break;
    else:
        print("틀렸습니다. 다시 입력하세요.")
        count += 1

if good == 0:
    print("틀렸습니다.")
    print("정답을 찾지 못하고 종료, b는", b, "입니다")
