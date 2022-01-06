'''14주차 수업내 코딩
버튼 2개 만든다
첫번째 버튼을 한번 클릭하면 강아지 사진을 보여주고,
더블 클릭하면 사진이 사라지면서 “disappear”이라고 띄운다. 
두번째 버튼을 한번 클릭하면 고양이 사진을 보여주고,
더블 클릭하면 사진이 사라지면서 “disappear”이라고 띄운다. 
'''
from tkinter import *
from tkinter import Tk, Canvas
from PIL import ImageTk, Image
import sys

root = Tk()
canvas = Canvas(root, width = 400, height = 300)
canvas.pack()


def showImage1(event) : 
    print("강아지 사진을 출력합니다.")
    im = Image.open('dog.jpg')
    canvas.image = ImageTk.PhotoImage(im)
    canvas.create_image(0,0,image=canvas.image,anchor = 'nw')

def showImage2(event) : 
    print("고양이 사진을 출력합니다.")
    im = Image.open('cat.jpg')
    canvas.image = ImageTk.PhotoImage(im)
    canvas.create_image(0,0,image=canvas.image,anchor = 'nw')

def disappear(event) : 
    print("disappear")
    canvas.delete()
    sys.exit()


Button1 = Button(None, text='Dog') 
Button1.pack()
Button1.bind('<Button-1>', showImage1) 
Button1.bind('<Double-1>', disappear)

Button2 = Button(None, text='Cat') 
Button2.pack() 
Button2.bind('<Button-1>', showImage2) 
Button2.bind('<Double-1>', disappear) 

root.mainloop()

