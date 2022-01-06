#7주차 수업내 코딩

import turtle

wn = turtle.Screen()
wn.bgcolor("lightblue")
t = turtle.Turtle()
t.shape("turtle")
t.color("hotpink")

t.penup()
size = 20

for i in range(50) :
    t.stamp()
    size = size + 3
    t.forward(size)
    t.right(24)
