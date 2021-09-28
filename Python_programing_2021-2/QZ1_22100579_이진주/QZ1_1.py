#5주차 퀴즈1
#22100579 이진주 
#1

num = int(input("정수를 입력해주세요 : "))

if num < 0 :
    print("음수입니다. ")
elif num == 0 :
    print("0입니다. ")
elif num % 3 == 0 :
    if num % 2 == 0 :
        print("3의 배수인 짝수입니다. ")
    else :
        print("3의 배수인 홀수입니다. ")
else :
    if num % 2 == 0 :
        print("짝수입니다. ")
    else :
        print("홀수입니다. ")

    

