#HomeWork 10week2
#22100579이진주
''' 숫자야구 게임
    0~9의 숫자로 구성된 4개 아이템인 리스트를 생성하여 화면에 출력한다.
    이 때 각 아이템의 값은 중복되지 않게 한다.
    random.sample(range(0, 10), 4)을 활용한다.
    이 값이 컴퓨터가 만들어 놓은 숫자 리스트이다.

    컴퓨터가 만들어 놓은 숫자 리스트를 맞추기 위하여 사용자에게 4개의 정수를
    입력 받아 리스트를 구성한다. 이 때, 입력 값이 0~9 사이가 아닐 때는
    "Please input a number from 0 to 9" 를 출력 후 다시 입력 받도록 한다.
    그리고, 사용자가 입력한 수 중에 중복되는 수가 있는 경우 "Duplicate number"
    를 출력하여 다른 수를 입력 받아 중복되지 않도록 구성한다.
    이때, 중복여부를 확인하는 함수 check_list(listname,input_num) 을 만들어
    사용한다.

    컴퓨터가 만든 리스트의 아이템과 사용자가 입력한 리스트 아이템의
    위치와 값이 같으면 strike, 위치는 다르지만 값이 같으면 ball 로 판정하여
    그 결과를 화면에 출력한다.
    [1,2,3,4] 가 컴이 만든 리스트이고 [4,2,3,9] 사용자가 입력한 리스트라면
    위치와 값이 같은 것은 2와 3으로 2strike이고 위치는 다르지만 값이 있는 4가
    한 개 있으므로 1ball 이다. "2-strike, 1-ball" 이라고 출력한다

    사용자가 입력한 값을 받을 때마다 횟수를 센다.
    컴퓨터가 만든 리스트 값을 맞출 때까지 반복한다.
    사용자가 컴퓨터가 설정한 값을 맞췄을 때, 맞추기까지 걸린 횟수를 함께 출력

    컴퓨터가 설정한 리스트: [9, 7, 1, 5]

    >>> Input a number : 11
    Please input a number from 0 to 9
    >>> Input a number : 5
    >>> Input a number : 3
    >>> Input a number : 4
    >>> Input a number : 1
     0 strike, 2 ball

    >>> Input a number : -1
    Please input a number from 0 to 9
    >>> Input a number : 5
    >>> Input a number : 1
    >>> Input a number : 5
    Duplicate number
    >>> Input a number : 4
    >>> Input a number : 7
    0 strike, 3 ball

    >>> Input a number : 7
    >>> Input a number : 3
    >>> Input a number : 1
    >>> Input a number : 5
    2 strike, 1 ball    

    >>> Input a number : 9
    >>> Input a number : 7
    >>> Input a number : 1
    >>> Input a number : 5
    4-strike, 0-ball

     

    You win! on 4 try..


 '''
import random

list_com = random.sample(range(0, 10), 4)
list_user = []
str_count = 0
ball_count = 0
try_count = 0
success = False

def check_list(listname,input_num): #중복검사 함수 
    for i in range(len(listname)):
        if listname[i] == input_num : #겹치는게 있으면 1 반환
            return 1
    return 0 #하나도 안겹쳤으면 0 반환

print("컴퓨터가 설정한 리스트:", list_com)

while not success :
    k = 0
    while k < 4: #입력받기~ 
        num = int(input(">>> Input a number :"))
        if num > 9 or num < 0:
            print("Please input a number from 0 to 9")
        else:
            if check_list(list_user,num) == 1:
                print("Duplicate number")
            else:
                list_user.append(num)
                k += 1

    
    for i in range(4): #판정하기 
        if list_user[i] in list_com :
            if list_user[i] == list_com[i]:
                str_count += 1 #스트라이크
            else:
                ball_count += 1 #볼

    print(str_count, "strike, ",ball_count, "ball")
    print()
    try_count += 1

    if str_count == 4: #탈출조건 검사하기 
        success = True
        break

    str_count = ball_count = 0 #다음 회차를 위한 초기화 
    list_user = []


print("You win! on", try_count," try..")
    


