from tkinter import *
screen = Tk()
screen.configure(bg='black')
screen.title("Rupin's game")
screen.geometry('450x500')
from random import randint
tex=IntVar()
operator = 0

entry1=Entry(screen,bg='orange',font=('arial',26,'bold'),bd=30,textvariable=tex)
entry1.grid(row=0,columnspan=3)


def click(number):
    global operator
    val=randint(0,10)
    if val==number:
        print('out')
        operator=0

    else :
        operator+=number
        print(operator)
        tex.set(operator)



btn7=Button(screen,text='7',bg='purple',font=('arial',26,'bold'),bd=12,command=lambda:click(7))
btn7.grid(row=1,column=0)

btn8=Button(screen,text='8',bg='purple',font=('arial',26,'bold'),bd=12,command=lambda:click(8))
btn8.grid(row=1,column=1)

btn9=Button(screen,text='9',bg='purple',font=('arial',26,'bold'),bd=12,command=lambda:click(9))
btn9.grid(row=1,column=2)



btn4=Button(screen,text='4',bg='purple',font=('arial',26,'bold'),bd=12,command=lambda:click(4))
btn4.grid(row=2,column=0)

btn5=Button(screen,text='5',bg='purple',font=('arial',26,'bold'),bd=12,command=lambda:click(5))
btn5.grid(row=2,column=1)

btn6=Button(screen,text='6',bg='purple',font=('arial',26,'bold'),bd=12,command=lambda:click(6))
btn6.grid(row=2,column=2)



btn1=Button(screen,text='1',bg='purple',font=('arial',26,'bold'),bd=12,command=lambda:click(1))
btn1.grid(row=3,column=0)

btn2=Button(screen,text='2',bg='purple',font=('arial',26,'bold'),bd=12,command=lambda:click(2))
btn2.grid(row=3,column=1)

btn3=Button(screen,text='3',bg='purple',font=('arial',26,'bold'),bd=12,command=lambda:click(3))
btn3.grid(row=3,column=2)



btn0=Button(screen,text='0',bg='purple',font=('arial',26,'bold'),bd=12,command=lambda:click(0))
btn0.grid(row=4,column=0)

screen.mainloop()