import turtle

painter = turtle.Turtle()
painter.pencolor("blue")
for i in range(3):
    painter.forward(123)
    painter.left(123*2)

painter.right(123)
painter.right(90)
painter.penup()

painter.forward(10)
painter.left(90)
painter.pendown()

painter.circle(70)
turtle.done()

