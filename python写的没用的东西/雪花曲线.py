import turtle

def snow(n, size):
    if n==0:
        turtle.fd(size)
    else:
        for angle in [0,60,-120,60]:
            turtle.left(angle)
            snow(n-1, size/3)
#输入n表示雪花曲线级数
n = int(input())

turtle.setup(1920, 1080)
turtle.speed(1000)
turtle.penup()
turtle.goto(-300, 300)
turtle.pendown()
turtle.pensize(1)
snow(n, 600)
turtle.right(120)
snow(n, 600)
turtle.right(120)
snow(n, 600)
turtle.done()