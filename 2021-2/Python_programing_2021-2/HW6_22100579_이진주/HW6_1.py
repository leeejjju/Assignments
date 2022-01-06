#HomeWork 13week1
#22100579이진주
'''1.	파일 읽어서 내용 확인하기  def CountFile(filename): 
텍스트 파일을 읽어서 단어 수, 문자 수(공백제외), 문자 수(공백포함), 줄수를
리턴하는 함수를 작성하시오. 생성한 함수를 호출하여 그 결과를 “output.txt”
에 저장하고 파일을 다시 읽어 그 내용을 출력하시오.

[주의사항] 
①파일을 오픈할 때 try ~ except 구문을 반드시 사용한다
②문자 수를 셀 때, 공백 포함 여부와 관계없이 줄 바꿈 문자인'\n'을 함께 세지 않는다 
③입력 받는 파일은 미리 만들어 놓고 시작한다
④입력 받는 파일과 “output.txt”을 zip해서 코드와 같이 제출한다


[“output.txt” 내용]
단어 수: 37
문자 수(공백제외): 170
문자 수(공백포함): 202
줄 수: 5
'''

def CountFile(filename):
    file = open(filename, "r")
    counts = [] #차례로 단어수, 공포문자수, 공미포문자수, 줄 수 입력해서 반환할 리스트 
    countWord = 0
    countLetter = 0
    countLetterB = 0
    countLine = 0
    
    lines = file.readlines()

    for i in range(len(lines)):
        for j in lines[i]:
            if j != ' ':
                countLetter += 1
            countLetterB += 1
        countLine += 1
        countWord += len(lines[i].split(" "))

    countLetter -= (countLine - 1)
    countLetterB -= (countLine - 1)

    counts.append(countWord)
    counts.append(countLetter)
    counts.append(countLetterB)
    counts.append(countLine)

    file.close()

    return counts
    
        
      
#텍스트 파일을 읽어서 단어 수, 문자 수(공백제외), 문자 수(공백포함), 줄수를 리턴


filename = input("분석할 파일명을 입력하세요")
counts = []

try:
    counts = CountFile(filename)

    
except IOError:
    print("파일이 존재하지 않습니다.")
    
else:
    print("파일을 성공적으로 분석했습니다.")
    
    

#생성한 함수를 호출하여 그 결과를 “output.txt”에 저장하고

f = open("output", "w")
ss = "단어 수: " + str(counts[0]) +'\n'
f.write(ss)
ss = "문자 수(공백제외): " + str(counts[1]) +'\n'
f.write(ss)
ss = "문자 수(공백포함): " + str(counts[2]) +'\n'
f.write(ss)
ss = "줄 수: " + str(counts[3])
f.write(ss)

f.close()


#파일을 다시 읽어 그 내용을 출력하시오.

file = open("output", "r")
lines = file.readlines()


for i in range(len(lines)):
    print(lines[i], end='')
        
