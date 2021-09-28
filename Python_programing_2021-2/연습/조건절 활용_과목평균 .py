#조건문의 활용 연습하기

kor = int(input("korean score?"))
eng = int(input("english score?"))
math = int(input("math score?"))

sum = (kor + eng + math)
ave = (sum / 3)

print('whole score is ', sum, 'average is ', ave)

#if ave >= 60 :
#   if kor < 50 or eng < 50 or math < 50 :
#       print('nonPass') #과락 
#else :
#   print('pass')

if ave >= 60 and kor >= 50 and eng >= 50 and math >= 50 :
    print('Pass') 
else :
    print('nonPass')

                
