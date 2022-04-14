#HomeWork 6week1
#22100579 이진주
'''리스트word=[ ‘apple’, ‘axes’, ‘book’, ‘box’, ‘buzz’, ‘cat’,
‘cantus’, ‘church’, ‘dish’, ‘knife’, ‘lady’, ‘leaf’,  ‘pitch’,
‘stimulus’, ‘taxi’, ‘wish’, ‘wolf’ ]는
단수명사들로 구성된 리스트이다.
각 아이템들을 복수명사로 만들어, plural 라는 리스트에 추가한 후
그 결과를 출력 하시오. 복수명사를 만드는 기준은 다음과 같다.
 

a. 명사의 끝이 “y”이면 “y”를 제외하고 “ies”를 붙인다.

b. 명사의 끝이 “f”, “fe” 이면 “f”, “fe”를 제외하고 “ves”를 붙인다.

c. 명사가 “s”, “x”, “z”, “ch”, “sh” 로 끝나면, “es”를 붙인다.

d. 명사가 “us” 로 끝나면, “us”를 제외하고 “i”를 붙인다.

e. 위의 4가지 경우가 아니면 “s”를 붙인다.


'''










word = ['apple', 'axes', 'book', 'box', 'buzz', 'cat', 'cantus', 'church', 'dish', 'knife', 'lady', 'leaf',  'pitch', 'stimulus', 'taxi', 'wish', 'wolf' ]



plural = list()

for one in word :
    
    if one[-1] == 'y' :
        one = one. replace('y', 'ies')
        
    elif one[-1] == 'f':
        one = one. replace('f', 'ves') 

    elif one[-1] == 'e' and one[-2] == 'f' :
        one = one. replace('fe', 'ves') 
        
    elif one[-1] == 's' or one[-1] == 'x' or one[-1] == 'z' or (one[-1] == 'h' and (one[-2] == 'c' or one[-2] == 's')):
        one += 'es'

    elif one[-1] == 's' and one[-2] == 'u':
        one = one. replace('us', 'i')

    else :
        one += 's'

    #print(one)
        

    plural.append(one)
        
    


for i in plural :
    
    print(i)






    
