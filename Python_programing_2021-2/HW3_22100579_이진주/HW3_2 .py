#HomeWork 6week2
#22100579 이진주
'''정수로 된 30개 원소로 구성된 리스트를 만들어,
그 중에서 가장 많이 반복된 숫자를 찾아 그 숫자와 반복횟수를 출력하고
가장 큰 수도 찾아 출력한다. 빈도수가 같은 값이 있다면 모두 다 출력하시오.
'''
#도저히 구현방법을 모르겠어서 몇몇 요소는 구글링 참고했습니다..ㅠ

from collections import Counter

list = [1, 22, 3, 33, 3, 58, 6, 27, 48, 933, 15, 2, 4, 6, 2, 4, 26, 3, 36, 7, 23, 31, 43, 4, 1, 9, 3, 12, 54, 47]
joong = []
count = 0
max = 0


for i in range(len(list)) :
    for j in range(i, len(list)) : #중복검사 
        if i != j and list[j] == list[i] :
            joong.append(list[j])
            count += 1
    if list[i] > max :
        max = list[i]

most = Counter(list)


print("입력된 정수들 중 중복된 수는 ", count, '개 입니다.')
print("가장 많이 중복된 숫자는 ", most.most_common(1)[0][0])
print("최대값은 ", max)
        
