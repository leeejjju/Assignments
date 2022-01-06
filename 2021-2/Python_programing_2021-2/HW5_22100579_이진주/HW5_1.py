#HomeWork 10week1
#22100579이진주
'''py, 다음을 구현할 때 기능과 관련된 내장함수나 METHOD는 사용하지 않는다.
다음의 기능을 하는 함수를 정의하고 3번씩 실행하시오'''
#1) def middle(string)
'''문자열 내의 정 가운데 글자를 리턴한다.
문자열의 문자 수가 홀수면, 정 가운데 한 글자를,
짝수이면 가운데 2개 글자를 리턴한다.
>>> print(middle(“middle”))

    dd

>>> print(middle(“miDdle”))

    Dd

>>> print(middle(“character”))

    a'''

def middle(string) :
    leng = len(string)
    if leng%2 == 0 :
        print(string[len(string)//2-1], string[len(string)//2])
    else :
        print(string[len(string)//2])

	
print(middle("middle"))
print(middle("miDdle"))
print(middle("character"))




#2)  def countVowels(string)

'''문자열 내의 모음(‘a’, ‘e’, ‘i’, ‘o’, ‘u’) 총 개수를 세어 리턴한다
    - 개수를 셀 때, 대소문자를 모두 센다.

>>> print(countVowles("she sElls seashells by thE seashore"))

모음의 총 개수: 10

>>> print(countVowles("I am Groot!"))

모음의 총 개수: 4

>>> print(countVowles("Let`s learn python TOGETHER!"))

모음의 총 개수: 7'''

moum = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']

def countVowels(string) :
    count = 0
    for i in string:
        if i in moum :
            count += 1
    return count
    

print('모음의 총 개수:', countVowels("she sElls seashells by thE seashore"))
print('모음의 총 개수:',countVowels("I am Groot!"))
print('모음의 총 개수:',countVowels("Let`s learn python TOGETHER!"))
 

#3)  def reverse(string)

'''문자열을 거꾸로 만들어서 리턴한다.

>>> print(reverse(“hello”))

olleh

>>> print(reverse(“Python”))

nohtyP

>>> print(reverse(“level”))

level

'''

def reverse(string):
    rever = []
    for i in range(len(string)-1, -1, -1):
        rever.append(string[i])
    result = ''.join(rever)
    return result
    
print(reverse("hello"))
print(reverse("Python"))
print(reverse("level"))


    


