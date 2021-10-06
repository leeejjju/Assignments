#HomeWork 6week2
#22100579 이진주
'''정수로 된 30개 원소로 구성된 리스트를 만들어,
그 중에서 가장 많이 반복된 숫자를 찾아 그 숫자와 반복횟수를 출력하고
가장 큰 수도 찾아 출력한다. 빈도수가 같은 값이 있다면 모두 다 출력하시오.
'''
count = 0

for i in range(30) :
    array[i] = int(input('정수 입력 : '))
    for j in range(len(array)) : #중복검사 
        if j != 0 and array[j] == array[i] :
            count += 1
            #빈도수는 엌카지??

print("입력된 정수들 중 중복된 수는 ", count, '개 입니다.')
        
