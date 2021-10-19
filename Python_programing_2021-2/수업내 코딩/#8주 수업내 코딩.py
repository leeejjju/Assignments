#8주차 수업내코딩
#함수이름과 변수이름은 겹쳐선 안됨!!!

def sum(a, b, c) :
    sm = a + b - c
    print(sm)

for i in range(10) :
    print(" --- ", i+1, "번째 실행 --- ")
    a = int(input("첫번째 수를 입력하세요 "))
    b = int(input("두번째 수를 입력하세요 "))
    c = int(input("세번째 수를 입력하세요 "))
    sum(a, b, c)


def product(a, b, c) :
    sm = a * b * c
    return sm

r = product(2, 3, 5) + product(5, 7, 11)
print(r)


