#HW2-2
#아래 표의 기준과 같이 점수와 성적 유형을 입력 받고 학점을 계산하는 프로그램을 작성하시오. (if문 사용)

# Score(float)
#Letter >> PF
#100 ~ 90 >> A, PD(Pass with Distinction)
#Below 90 ~ 80 >> B, Pass
# Below 80 ~ 70 >> C, Pass
# Below 70 ~ 60 >> D, Pass
# Below 60 >> F, Fail


score = float(input(">>> Input your score  : ")) #점수와 평가방식 입력 
kind = input(">>> Input Letter(L) or PF(PF) : ")

if kind == 'PF' : #PF일 경우 성적산출 
    if score >= 90 :
        grade = 'PD(Pass with Distinction)'
    elif score >= 60 :
        grade = 'Pass'
    else :
        grade = 'Fail'
elif kind == 'L' or kind == 'Letter' : #Letter Grade일 경우 성적산출 
    if score >= 90 :
        grade = 'A'
    elif score >= 80 :
        grade = 'B'
    elif score >= 70 :
        grade = 'C'
    elif score >= 60 :
        grade = 'D'
    else :
        grade = 'F'

print("Your grade is ", grade) #성적 출력 



    
