#5주차 3강 중첩반복문 연습문제1
#단어와 단어 속의 글자 하나 입력받고, 글자가 단어의 몇번쨰 위치에 있는지 출력 

word = input("input any word : ")
letter = input("input any letter : ")
count = 1
none = True

for i in word :
    
    if i == letter :
        print(i, '는 단어의 ', count, '번째에 있습니다.')
        none = False
        break
    
    count += 1

if none ==True :
    print("해당 글자는 단어 속에 없습니다. ")


