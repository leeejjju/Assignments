#HomeWork 15week2
#22100579이진주
'''2.	앞으로 읽어도 뒤에서부터 읽어도 같은 단어 또는 문장 확인하기 
[tkinter 활용] isPalindrome.py   
입력 된 문자열이 다음과 같이 앞으로 읽으나 뒤로 읽으나 같은 단어이면
True를 출력하고 아니면 False를 출력하는 프로그램을 작성하시오. 
해당하는 예를 아래와 같다
“deed”, “Noon”, “rotor”, “race car”, “put it up”,
“Step on no pets!”, “Rise to vote, sir”
이 때 tkinter를 활용하여 문자열을 입력 받고(Entry 사용),
결과 button(button 사용)을 누르면 True or False를 출력하시오(Label 사용).

[주의사항] 
①	문장 안의 스페이스나 특수문자는 무시하고 확인한다.
②	대소문자 구분은 하지 않는다.
'''
import tkinter

window = tkinter.Tk()#윈도우창 

window.title("isPalindrome,py")#윈도우창 제목 설정
window.geometry("300x100+100+100")#윈도우창 너비, 높이, 초기화면의 x,y좌표
window.resizable(True, True)#윈도우 창의 크기조절 가능 여부

explain = tkinter.Label(window, text="Input a string to check palindorome or not")#라벨 위젯 생성
explain.pack() #위젯 배치

TF = tkinter.Label(window, text="haha")


def isPalindrome(line):
    enil = []#문자열 거꾸로 집어넣을 빈 리스트
    
    for i in range(len(line)): #거꾸로 집어넣음 
        enil.append(line[len(line)-i-1])

    same = 1
    for i in range(len(line)):
        if not line[i] == enil[i]:
            same = 0

    if same == 0:
        TF.config(text = "False")
    else:
        TF.config(text = "True")


#대소문자 구분 없애고(다 대문자로) 특수문자 없애주는 함수
def clean(line):
    line = line.upper()#다 대문자로 바꾸고 
    line = list(line)#리스트로 바꿔주고

    i = 0
    L = len(line)
    while(1):
        if i == L:
            break   
        if not line[i].isupper(): #문자가 아니면
            line.pop(i)#없애고
            L -= 1#길이 줄임
        else:
            i += 1

    return line


def onClick():
    line = entry.get()
    isPalindrome(clean(line))
    TF.pack()


entry = tkinter.Entry(window)
entry.bind("<Button-1>")
entry.pack()

check = tkinter.Button(window, text="Check", command=onClick)
check.pack()


window.mainloop()#윈도우가 종료될때까지 반복

