#fruit lists

fruits = ['apple', 'banana', 'grape', 'orange', 'strawberry']

fruit_input = input("what is your favorit fruit?")

if fruit_input in fruits :
    print('the fruit is in the list')

elif fruit_input == "없음" :
    print("oh no why")

else :
    print("the fruit is not in the list")


print(fruits[0], fruits[1], fruit_input)
print(fruits)
