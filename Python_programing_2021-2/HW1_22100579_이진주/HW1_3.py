#HomeWork 1week-3
#22100579 이진주

# 2개의 숫자를 입력 받아 더한 결과와 곱한 결과를 출력한다.
# >>> 첫번째 숫자를 입력하시오 : 5

# >>> 두번째 숫자를 입력하시오 : 53

#  더한 결과는 58 이고, 곱한 결과는 265 입니다.

 
from typing import MutableMapping


fstNum = input("첫번째 숫자를 입력하시오 : ")
sndNum = input("두번째 숫자를 입력하시오 : ")

plusNum = int(fstNum) + int(sndNum)
mtpNum = int(fstNum) * int(sndNum)

print('더한 결과는', plusNum, '이고, 곱한 결과는', mtpNum, '입니다.');