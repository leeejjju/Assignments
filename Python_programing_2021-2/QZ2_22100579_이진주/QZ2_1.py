#12주차 퀴즈2
#22100579 이진주 
#1

'''문자열을 입력받아 문자열의 특징을 찾아내는 함수를 작성하고 결과를 출력하라
앞으로읽으나 뒤로읽으나 같은지 판별하는 ispal(str). 대소문자구분, 공백 기호는
고려하지 않는다.
transfer 문자열을 암호화. 대소문자도 변경. 딕셔너리를 선언하여 사용한다.
알파벳이 아닌 문자는 그대로 둔다. '''


moon = input("문자열 입력 : ")

def ispal(s):
    org = []
    gro = []
    
    for i in s:
        if (i.isalpha()) :
            i.upper()
            org.append(i)


    for i in range(len(org)):
        gro.append(org[len(org)-1-i])


    if org == gro:
        return True
    else:
        return False

if ispal(moon):
    print(moon, "은(는) PALINDROME이며,")
else:
    print(moon, "은(는) PALINDROME이 아니며,")
    
            


o = "abcdefghijklnmopqrstuvwxyz"
o = o + o.upper()
p = "zyxwvutsrqponmlkjihgfedcba"
p = p + p.upper()

nnn = dict(list(zip(o, p)))


#print(nnn)

def transfer(s) :
    org = []
    pw = []
    
    for i in s:
        if (i.isalpha()) :
            if i.isupper() :
                i = i.lower()
                org.append(i)
            elif i.islower():
                i = i.upper()
                org.append(i)
            
        else:
            org.append(i)
            
            
    for i in org:
        if i.isalpha() :
            pw.append(nnn[i])
   
        else:
            pw.append(i)
    
    pww = ""

    for i in pw:
        pww = pww+ i

    return pww

print("변환 후 ", str(transfer(moon)), "입니다")

        
    
