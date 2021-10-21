import tkinter as tk
from tkinter import ttk
class Application(tk.Frame):
    
    def __init__(self, master=None):
        super().__init__(master)
        self.master = master
        master.title("binary to decimal")
        master.maxsize(900,600)
        master.config(bg = "pink")
        
        frame = tk.Frame(master,width=600,height=200,bg="white")
        frame.grid(row = 0,column = 0,padx=10,pady=5)

        label = ttk.Label(frame, text='Enter Binary Number:').grid(row = 0,column =0,padx = 5,pady=5 )    
        button = ttk.Button(frame, text='Convert',command=self.generate).grid(row = 0,column = 4,padx = 5,pady = 5)
       
        self.username = tk.StringVar()
        self.results  = tk.StringVar()
        answer = ttk.Label(frame,textvariable=self.results).grid(row=1,column=1,padx = 5 ,pady = 5)
        name = ttk.Entry(frame, textvariable=self.username).grid(row = 0, column = 1,padx = 5,pady=5)
        

    def generate(self,*args):
        value = str(self.username.get())
        try:
            value = str(self.username.get())
            self.results.set("Answer = {}".format(int(value,2)))
        except ValueError:
            self.results.set("Invalid Input {}".format(value))

root = tk.Tk()
app = Application(master=root)
app.mainloop()
