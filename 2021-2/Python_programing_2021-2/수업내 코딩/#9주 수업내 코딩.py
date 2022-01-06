#9주차

#1
#문자열과 문자를 입력받아 문자열에서 문자를 찾으면 그 문자의 위치를 출력.
#없으면 -1 출력

moon = input("문자열을 입력하세요: ")
ch = input("문자를 입력하세요: ")

def search (moon, ch) :
    index = -1
    for i in range(len(moon)) :
        if moon[i] == ch :
            index = i
    return index

            
print(ch, "은(는)", moon, "의 ", search(moon, ch), "번째에 있습니다.")




#2
#주사위 두개를 던져 같은 숫자가 나오면 반복, 다르게 나오면 종료.
#결과를 화면에 모두 출력


while(1) :
    n1 = int(input("첫번째 숫자를 입력하세요"))
    n2 = int(input("두번째 숫자를 입력하세요"))
    if n1 == n2 :
        print("같습니다")
    elif n1 > n2 :
        print(n1, "이(가) 더 큽니다")
        break
    else :
        print(n2, "이(가) 더 큽니다")
        break


