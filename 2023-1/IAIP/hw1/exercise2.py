#execise2

s = int(input("Enter the start day (0~6)>> "))
days = int(input("Enter the number of days (1~31)>> "))

print("Sun  Mon  Tue  Wed  Thu  Fri  Sat")

yoil = s;

# print('     '*(s-1), end='')
print('     '*(s), end='')

for i in range (1, days+1):
  #change yoil
  if(yoil % 7 == 0):
    print()

  print(" %2d  " % i, end='')
  yoil += 1





