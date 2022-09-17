#fill= X,Y to expand along x and y axis
# to get a message box
# response= messagebox. return is 1 and 0 |for ask question it is yes or no all other return ok
#      showinfo,showwarning,askquestion,showerror,askokcancel,askyesno
# image in new window should be global
# config to change the attribute
# state of button can be disabled
# ipad for inner space and justify for aligning

from numpy import source


source=[]
from tkinter import *
from tkinter import ttk
from PIL import ImageTk,Image
from matplotlib import image
from tkinter import filedialog
global x
global y
global count
x= 80

class start:
    def __init__(self,master):
       self.canvas=Canvas(sec,bg="white",width=800,height=200)
       (self.canvas).pack()
       (self.canvas).create_text(20,20,text="asd")
       



root=Tk()
root.title('testing')
root.iconbitmap('C:/Users/91964/Desktop/GITHUB/sem2/DS/project/new_project/2.ico')

main=Frame(root,bg="yellow")
main.pack(fill=BOTH,expand=1)

canvas=Canvas(main,bg="green")
canvas.pack(side=LEFT,fill=BOTH,expand=1)

scrollbar=ttk.Scrollbar(main,orient=VERTICAL,command=canvas.yview)
scrollbar.pack(side=RIGHT,fill=Y)

canvas.configure(yscrollcommand=scrollbar.set)
canvas.bind('<Configure>',lambda e: canvas.configure(scrollregion=canvas.bbox("all")))

sec=Frame(canvas,bg="red",width=800,height=800)

# source.append(Canvas(sec,bg="white",width=800,height=200))

def create():
    source.append(start(sec))
    # (source[-1]).pack()
    # (source[-1]).create_text(20,20,text="hello")
    # (source[-1]).create_text(40,40,text="hello")
    # next()
    
# ls=["a","b","c","d"]

# def next():
#     global x
#     for i in source:

        
#         for j in ls:
#             i.create_text(60,60,text=j)
#             x+=20
#         i.after(500,next)
        


canvas.create_window((0,0),window=sec,anchor="nw")

b1=Button(sec,text="Create",command=create)
b1.pack()




# my_img=ImageTk.PhotoImage(Image.open('C:/Users/91964/Desktop/GITHUB/sem2/DS/project/new_project/download.png'))
# my_label=Label(root,image=my_img)
# my_label.grid(row=3,column=3)

root.mainloop()