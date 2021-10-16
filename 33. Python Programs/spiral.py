import turtle
a= turtle.Turtle()
for i in range(100):
    a.dot()
    a.forward(2+i/4) # or a.fd(2+i/4)
    a.penup()
    a.left(30-i/4)
turtle.done()
