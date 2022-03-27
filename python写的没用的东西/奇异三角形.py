#奇异三角形
import turtle

def tri(n, size):
    if n==0:
        turtle.left(60)
        turtle.fd(size)
        turtle.right(120)
        turtle.fd(size)
        turtle.right(120)
        turtle.fd(size)
    else:
        x, y = turtle.pos()
        pos = turtle.pos()
        tri(n-1, size/2)
        turtle.goto(pos)
        turtle.goto(x+size/2, y)
        turtle.right(180)
        pos = turtle.pos()
        tri(n-1, size/2)
        turtle.goto(pos)
        turtle.right(60)
        turtle.fd(size/2)
        turtle.right(120)
        tri(n-1, size/2)
#输入n，表示三角形级数
n = int(input())
turtle.setup(1600, 900)
turtle.speed(5000)
turtle.penup()
turtle.goto(-270, -200)
turtle.pendown()
turtle.pensize(1)

tri(n, 540)
turtle.done()