import turtle
import winsound
import time

def main():
    win=turtle.Screen()
    win.title("Pong")
    win.bgcolor("black")
    win.setup(width=800,height=600)
    win.tracer(0)

    #score
    global score_a,score_b
    


    #paddle a
    paddle_a=turtle.Turtle()
    paddle_a.speed(0)
    paddle_a.shape("square")
    paddle_a.color("purple")
    paddle_a.shapesize(stretch_wid=5,stretch_len=1)
    paddle_a.penup()
    paddle_a.goto(-350,0)




    #paddle b
    paddle_b=turtle.Turtle()
    paddle_b.speed(0)
    paddle_b.shape("square")
    paddle_b.color("purple")
    paddle_b.shapesize(stretch_wid=5,stretch_len=1)
    paddle_b.penup()
    paddle_b.goto(350,0)

    #ball
    ball=turtle.Turtle()
    ball.speed(0)
    ball.shape("circle")
    ball.color("red")
    ball.penup()
    ball.goto(0,0)
    ball.dx=0.2
    ball.dy=-0.2

    #pen
    pen=turtle.Turtle()
    pen.speed(0)
    pen.color("green")
    pen.penup()
    pen.hideturtle()
    pen.goto(0,260)
    

    #Function
    def paddle_a_up():
        y=paddle_a.ycor()
        y+=20
        paddle_a.sety(y)
    def paddle_a_down():
        y=paddle_a.ycor()
        y-=20
        paddle_a.sety(y)

    def paddle_b_up():
        y=paddle_b.ycor()
        y+=20
        paddle_b.sety(y)

    def paddle_b_down():
        y=paddle_b.ycor()
        y-=20
        paddle_b.sety(y)    
     

    #keyboard binding
    win.listen()
    win.onkeypress(paddle_a_up,"w")
    win.onkeypress(paddle_a_down,"s")
    win.onkeypress(paddle_b_up,"Up")
    win.onkeypress(paddle_b_down,"Down")
    pen.write("Press 'Space Bar' To Start game",align="center",font=("Courier",24,"normal"))

    
    
    #main game loop
    def start():
        pen.clear()
        pen.write("Player A: 0           Player B: 0",align="center",font=("Courier",24,"normal"))

        score_a=0
        score_b=0
        v=4
        t=0
        while True:
            win.update()

            #move the ball
            ball.setx(ball.xcor() + ball.dx)
            ball.sety(ball.ycor() + ball.dy)

            if(paddle_a.ycor()>250):
                paddle_a.sety(250)
            if(paddle_b.ycor()>250):
                paddle_b.sety(250)
            if(paddle_a.ycor()<-250):
                paddle_a.sety(-250)
            if(paddle_b.ycor()<-250):
                paddle_b.sety(-250)


            #paddle and bal collisions
            if(ball.xcor()>340)and ball.xcor()<350 and (ball.ycor() < paddle_b.ycor()+40 and ball.ycor()>paddle_b.ycor()-40):
                ball.setx(340)
                ball.dx*=-1
                winsound.PlaySound("sound/258020__kodack__arcade-bleep-sound.wav",winsound.SND_ASYNC)
                
            if(ball.xcor()<-340) and ball.xcor()>-350 and (ball.ycor() < paddle_a.ycor()+40 and ball.ycor()>paddle_a.ycor()-40):
                ball.setx(-340)
                ball.dx*=-1
                winsound.PlaySound("sound/258020__kodack__arcade-bleep-sound.wav",winsound.SND_ASYNC)  
                

            #border checking
            if(ball.ycor()>290):
                ball.sety(290)
                ball.dy*=-1
                winsound.PlaySound("sound/4skwn-reh0j.wav",winsound.SND_ASYNC)        
                
            if(ball.xcor()>390):
                ball.goto(0,0)
                score_a+=1
                ball.dx*=-1
                pen.clear()
                pen.write("Player A: {}           Player B: {}".format(score_a,score_b),align="center",font=("Courier",24,"normal"))
                winsound.PlaySound("sound/4skwn-reh0j.wav",winsound.SND_ASYNC)

            if(ball.ycor()<-290):
                ball.sety(-290)
                ball.dy*=-1
                winsound.PlaySound("sound/4skwn-reh0j.wav",winsound.SND_ASYNC)
                
            if(ball.xcor()<-390):
                ball.goto(0,0)
                score_b+=1
                ball.dx*=-1
                pen.clear()
                pen.write("Player A: {}           Player B: {}".format(score_a,score_b),align="center",font=("Courier",24,"normal"))
                winsound.PlaySound("sound/4skwn-reh0j.wav",winsound.SND_ASYNC)
            t=max(score_a,score_b)

            if(t==5):
                ball.goto(0,0)
                winsound.PlaySound("sound/game-over-sound-effect.wav",winsound.SND_ASYNC)
                over=turtle.Turtle()
                over.ht()
                over.color("red")
                
                
                while(v>=0):
                    time.sleep(1)
                    if(t==score_b):
                        over.clear()
                        over.write("Player B Wins\n       {}".format(v),align="center",font=("Courier",44,"bold"))
                    else:
                        over.clear()
                        over.write("Player A Wins \n      {}".format(v),align="center",font=("Courier",44,"bold"))
                    #v=v-1
                    if(v==0):
                        break
                    v-=1 
            if(v==0):
                win.bye()
                break     
    win.onkeypress(start,"space")
    win.mainloop()     


if __name__=='__main__':
    main()
    
            
            
        
        
        
        
    
    
