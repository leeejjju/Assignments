#HomeWork 13week2
#22100579이진주
'''2.   마방진(Magic Square) 작성
7*7 로 구성된 리스트를 생성하여, magic square를 작성하여 출력하시오.
1부터 49까지의 연속된 자연수를 가로, 세로, 대각선의 합이 같아지도록
정사각형 모양으로 배열한다.

조건1. 1은 row 0, col 3 에 배치한다
조건2. 그 다음 수는 row, col 값을 -1한 후 배치한다.
이 때 그 위치에 값이 있거나 row, col이 모두 존재 하지 않는 곳이면
이전 숫자 위치의 바로 아랫쪽에 배치하고, row또는 col 값 중 하나만
존재하지 않으면 제일 오른쪽이나 제일 아랫쪽에 배치한다.

출력 예시) 결과는 빈 값을 채워 다음과 같이 7 x 7 행렬의 형태로 출력한다. 

[  ,  ,  , 1,  ,  ,   ]
[29,  ,  ,  ,  ,  , 38]
[  ,  ,  ,  ,17,  ,   ]
[  ,  ,  ,  ,  ,  ,  5]
[  ,44,  ,  ,  ,  ,   ]
[12,  ,  ,  ,  , 23,  ]
[  ,  , 2,  ,  ,   ,22]
'''


#배열생성
magicS = []
for i in range(7):
    line = [0, 0, 0, 0, 0, 0, 0]
    magicS.append(line)

#마방진을 채워볼까용...

num = 1
row = 0
col = 3

while(1):

    if num == 50:
        break

    if (row < 0 or row > 6) and (col < 0 or col>6):
        row += 2
        col += 1
        continue
        
    elif (row < 0 or row > 6):
        row = 6
        continue
        
    elif (col < 0 or col>6):
        col = 6
        continue
        
    elif magicS[row][col] == 0:
        magicS[row][col] = num
        #print("방금",num, "넣었음")
        num += 1
        row -= 1
        col -= 1
        continue
        
    elif not magicS[row][col] == 0:
        row += 2
        col += 1
        continue


#출력
    
for i in range(7):
    print(magicS[i])

    
    

