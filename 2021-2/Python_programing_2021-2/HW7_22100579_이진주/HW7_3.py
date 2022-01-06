#HomeWork 15week3
#22100579이진주
'''3.	Matplotlib
다음 표와 같은 분포일 때, legend를 표시하는 파이차트를 그리시오.
do	Percentage
Kyunggi	20
Chungcheng	20
Seoul	35
Jellra	15
kyungsang	10
'''
import matplotlib.pyplot as plt #pyplot을 plt라는 이름으로 접근하겠따~
import numpy as np

y = np.array([20,30,35,15,10])
tag =["Kyunggi","Chungcheng","Seoul","Jellra","kyungsang"]

plt.pie(y, labels= tag)
plt.legend(title= "Five Districts", loc="lower left")
plt.show()


