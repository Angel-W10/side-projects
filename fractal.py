from turtle import *
from random import randrange


# forward(100)
speed(0)
colormode(255)

def tree(size, level, angle, f):
    
    if(level==0):
        return
    
    #right tree branch
    color(randrange(256), randrange(256), randrange(256))
    forward(size)
    right(angle)
    color(randrange(256), randrange(256), randrange(256))
    tree(size*f, level-1, angle, f)
    
    # back to the center
    # left tree branch
    left(angle*2)
    color(randrange(256), randrange(256), randrange(256))
    tree(size*f, level-1, angle, f)
    
    # back to the center
    right(angle)
    backward(size)



if __name__ == "__main__":
 
    # f = 0.4669
    # turtle.screen().bgcolor("black")
    penup()
    goto(0, -150)
    pendown()
    f = 0.8

    Screen().bgcolor('black')
    color("blue")
    angle = 30
    size = 100
    level = 10
    left(90)
    # backward(200)
    tree(size, level, angle, f)
    mainloop()

