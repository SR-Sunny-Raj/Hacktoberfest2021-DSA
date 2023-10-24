import qrcode
from tkinter import*
from tkinter import PhotoImage

def generate():
    #Getting url from url variable
    url_qrcode = url.get()

    #Generating qrcode
    generated_url_qrcode = qrcode.make(url)

    #Saving qrcode
    generated_url_qrcode.save("qrcode.png")

    #Making new window for displaying generated qrcode
    new = Toplevel(root)
    img = PhotoImage(file="qrcode.png")
    label = Label(new,image=img)
    label.pack(pady=10)

    new.mainloop()

#Initializing Tk
root =  Tk()
root.geometry("300x180")

#Variable to store url enter by user
url = StringVar()

Label(text="Paste your url here").pack(pady=20)

#Entry widget for taking url input and store it into url variable
url_entry = Entry(textvariable=url)
url_entry.pack()

#Button for calling generate function
Button(text="Generate",command=generate).pack(pady=15)

root.mainloop()