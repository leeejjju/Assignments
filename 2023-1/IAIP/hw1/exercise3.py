#exercise3


#read
fp = open('input.txt', 'r')

ans = []

for line in fp:
  sum = 0
  s = line.split()
  for j in s:
    sum += float(j)
  ans.append(round(sum, 1))

fp.close()
fp = open('output.txt', 'w')

for i in ans:
  print(i)
  fp.write(str(i)+'\n')


fp.close()



