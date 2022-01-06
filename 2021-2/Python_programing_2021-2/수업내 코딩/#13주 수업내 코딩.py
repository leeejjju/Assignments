#13주차 수업내코딩
#이미지 하나를 다운로드하여 “test.jpg”로 저장한다
#정상 상태, 45도 회전 후, 90도 회전 후, 135도 회전 후 그림을 화면에 띄운다

from PIL import Image

try:
    im = Image.open("test.jpg")
except IOError as err:
    print("그런이미지업다")

im.show()
im.rotate(45).show()
im.rotate(90).show()

