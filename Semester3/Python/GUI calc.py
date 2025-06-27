import tkinter as tk
from tkinter import *

window = Tk()
window.title("Calculator")
window.geometry('500x200')

l1 = tk.Label(window, text = "Number 1 : ",font = ("Arial Bold",12))
l1.grid(column=0,row=0)
l2 = tk.Label(window, text = "Number 2 : ",font = ("Arial Bold",12))
l2.grid(column=0,row=1)
l3 = tk.Label(window, text = "Result : ",font = ("Arial Bold",12))
l3.grid(column=0,row=6)

e1=tk.Entry(window)
e1.grid(column=1,row=0)
e2=tk.Entry(window)
e2.grid(column=1,row=1)

def add():
    n1=int(e1.get())
    n2=int(e2.get())
    result = n1+n2
    l3.config(text=f" Result : {result}")
def sub():
    n1=int(e1.get())
    n2=int(e2.get())
    result = n1-n2
    l3.config(text=f" Result : {result}")
def mul():
    n1=int(e1.get())
    n2=int(e2.get())
    result = n1*n2
    l3.config(text=f" Result : {result}")
def div():
    n1=int(e1.get())
    n2=int(e2.get())
    result = n1/n2
    l3.config(text=f" Result : {result}")

b1 = tk.Button(window,text="Addition",width=20,height=1,font=("Arial Bold",12),command=add)
b1.grid(column=1,row=2)
b2 = tk.Button(window,text="Subtraction",width=20,height=1,font=("Arial Bold",12),command=sub)
b2.grid(column=2,row=2)
b3 = tk.Button(window,text="Multiplication",width=20,height=1,font=("Arial Bold",12),command=mul)
b3.grid(column=1,row=3)
b4 = tk.Button(window,text="Division",width=20,height=1,font=("Arial Bold",12),command=div)
b4.grid(column=2,row=3)
