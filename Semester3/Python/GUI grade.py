#Code to check if the average of 4 marks entered are >90,>80,>70 or less using GUI and form

import tkinter
from tkinter import *

root=Tk()
root.geometry("500x500")
root.title("Grade")

def grade():
    mark1=int(m1entry.get())
    mark2=int(m2entry.get())
    mark3=int(m3entry.get())
    mark4=int(m4entry.get())
    final=(mark1+mark2+mark3+mark4)/4
    if(final>90):
        result.config(text="excellent")
    elif(final>80):
        result.config(text="80 up")
    elif(final>70):
        result.config(text="70 up")
    else:
        result.config(text="Padhle bhai")
        

    
m1=Label(root,text="Marks 1")
m1.pack()
m1entry=Entry(root)
m1entry.pack()

m2=Label(root,text="Marks 2")
m2.pack()
m2entry=Entry(root)
m2entry.pack()

m3=Label(root,text="Marks 3")
m3.pack()
m3entry=Entry(root)
m3entry.pack()

m4=Label(root,text="Marks 4")
m4.pack()
m4entry=Entry(root)
m4entry.pack()

subbutton=Button(root,text="Submit",command=grade)
subbutton.pack()

result=Label(root,text="")
result.pack()

root.mainloop()
