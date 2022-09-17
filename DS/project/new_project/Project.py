# libraries used
from re import L
from tkinter import *
from turtle import bgcolor
from typing_extensions import Self
from PIL import ImageTk,Image
from tkinter import ttk

# list for inputting objects of all classes
source = []

# class for creating a variable of particular data type
class create:

	def __init__(self,master,y,dtype,name,value=None):
		self.dtype = dtype
		self.name = name
		self.value = value
		self.canvas = Canvas(master,bg="white",width=y,height=100)
		self.canvas.pack()
		self.canvas.create_text(300,50,text= str(name) + " = " + str(value) )
		self.canvas.create_oval(270,20,330,80)

	def parse(self,file):

		if self.value: 
			file.write(f"{self.dtype} {self.name} = {self.value};\n")
		else:
			file.write(f"{self.dtype} {self.name};\n")

# class for assigning a variable a value
class assign:

	def __init__(self,name,value):
		self.name = name
		self.value = value

	def parse(self,file):
		file.write(f"{self.name} = {self.value};\n")

# class for displaying output
class output:

	def __init__(self,value):
		self.value = value

	def parse(self,file):
		file.write(f"cout << {self.value};\n")

# class for inputting a value
class input:

	def __init__(self,name):
		self.name = name

	def parse(self,file):
		file.write(f"cin >> {self.name};\n")

# class for if and else condition
class _if:

	def __init__(self,condition,if_block,else_block=None):
		self.condition = condition
		self.if_block = if_block
		self.else_block = else_block

	def parse(self,file):

		file.write(f"if ({self.condition}){{\n")
		for i in self.if_block: 
			i.parse(file)
		file.write("}\n")

		if self.else_block:
			file.write(f"else {{\n")
			for i in self.else_block: 
				i.parse(file)
			file.write("}\n")

# class for a while loop
class _while:

	def __init__(self,condition,block):
		self.condition = condition
		self.block = block

	def parse(self,file):
		file.write(f"while ({self.condition}){{\n")
		for i in self.block: 
			i.parse(file)
		file.write("}\n")

# class for a for loop
class _for:

	def __init__(self,beg,end,step,block):
		self.beg = beg
		self.end = end
		self.step = step
		self.block = block

	def parse(self,file):
		file.write(f"for (int i={self.beg}; i<={self.end}; i=i+{self.step}){{\n")
		for i in self.block: 
			i.parse(file)
		file.write("}\n")

# graphical interface

# main window for diplaying program
main = Tk(None,None,'project',1)
main.state("zoomed")
main.config(bg="black")

main.iconbitmap('C:/Users/91964/Desktop/GITHUB/sem2/DS/project/new_project/2.ico')

# main heading as C++ GRAPHICS 
# text= Label(main, font=('Times New Roman',15,'bold'),text="C++ GRAPHICS",bg="#2B55A9")
# text.grid(row=0,column=0)

top=LabelFrame(main,text="options",bg="cyan",padx=10,pady=10)
top.pack(side=TOP,anchor=NW,padx=5,pady=5,fill=X)
# frame for placing tools
tools=LabelFrame(main,bg="yellow",text="tools",padx=10,pady=10)
tools.pack(side=LEFT,anchor=NW,padx=5,pady=5,fill=Y)


# frame for displaying the flowchart  
graphic=LabelFrame(main,bg="green",text="flowchart",padx=10,pady=10)
graphic.pack(side=LEFT,padx=5,pady=5,anchor=NW)

# frame for displaying code
code=LabelFrame(main,bg="blue",text="code",padx=10,pady=10)
code.pack(side=RIGHT,padx=5,pady=5,anchor=NW)

frame1= Frame(graphic,width=600,height=800)
frame1.pack(fill=BOTH,expand=1)

frame2= Frame(code,width=400,height=800)
frame2.pack(fill=BOTH,expand=1)

canvas1=Canvas(frame1,width=600,height=800)
canvas1.pack(side=LEFT,fill=BOTH,expand=1)

canvas2=Canvas(frame2,width=400,height=800)
canvas2.pack(side=LEFT,fill=BOTH,expand=1)

scrollbar1= ttk.Scrollbar(frame1,orient=VERTICAL,command=canvas1.yview)
scrollbar1.pack(side=RIGHT,fill=Y)

scrollbar2= ttk.Scrollbar(frame2,orient=VERTICAL,command=canvas2.yview)
scrollbar2.pack(side=RIGHT,fill=Y)

canvas1.configure(yscrollcommand=scrollbar1.set)
canvas1.bind('<Configure>',lambda e:canvas1.configure(scrollregion=canvas1.bbox("all")))

canvas2.configure(yscrollcommand=scrollbar2.set)
canvas2.bind('<Configure>',lambda e:canvas2.configure(scrollregion=canvas2.bbox("all")))

area1=Frame(canvas1,width=600,height=800)
area2=Frame(canvas2,width=400,height=800,bg="red")

canvas1.create_window((0,0),window=area1,anchor=NW,width=600,height=800)
canvas2.create_window((0,0),window=area2,anchor=NW,width=400,height=800)

st1=Canvas(area1,width=600,height=100,bg="white")
st1.pack()
st1.create_text(300,50,text= "START" )
st1.create_oval(250,20,350,80)
st1.create_line(300,80,300,100)

# functions called while using tools buttons

def CREATE():

    global pop1
    pop1=Toplevel(main)
    pop1.title("Create")
    pop1.geometry("500x200")
    
    def INSERT():

        source.append(create(area1,600,Edtype.get(),Ename.get(),Evalue.get()))
        pop1.destroy()
    
    Cframe=Frame(pop1,width=500,height=200)
    Cframe.pack(anchor=CENTER)

    Clabel = Label(Cframe,text="Create a variable")
    Clabel.grid(row=0,column=6,padx=20,pady=20)

    Edtype= Entry(Cframe,width=20)
    Edtype.grid(row=3,column=3,padx=20,pady=20)
    Edtype.insert(0,"Enter data type")

    Ename= Entry(Cframe,width=20)
    Ename.grid(row=3,column=6,padx=20,pady=20)
    Ename.insert(0,"Enter name")

    Evalue= Entry(Cframe,width=20)
    Evalue.grid(row=3,column=9,padx=20,pady=20)
    Evalue.insert(0,"Enter value")

    Cbutton=Button(Cframe,text='ENTER',width=10,command=INSERT)
    Cbutton.grid(row=6,column=6,padx=20,pady=20)


def ASSIGN():

    global pop2
    pop2=Toplevel(main)
    pop2.title("Create")
    pop2.geometry("500x200")
    
    def INSERT():

        source.append(assign(Ename.get(),Evalue.get()))
        pop2.destroy()
    
    Cframe=Frame(pop2,width=500,height=200)
    Cframe.pack(anchor=CENTER)

    Clabel = Label(Cframe,text="Assign the variable a value")
    Clabel.grid(row=0,column=7,padx=20,pady=20)

    Ename= Entry(Cframe,width=20)
    Ename.grid(row=3,column=6,padx=20,pady=20)
    Ename.insert(0,"Enter name")

    Evalue= Entry(Cframe,width=20)
    Evalue.grid(row=3,column=8,padx=20,pady=20)
    Evalue.insert(0,"Enter value")

    Cbutton=Button(Cframe,text='ENTER',width=10,command=INSERT)
    Cbutton.grid(row=6,column=7,padx=20,pady=20)

def INPUT():

    global pop3
    pop3=Toplevel(main)
    pop3.title("Create")
    pop3.geometry("500x200")
    
    def INSERT():

        source.append(output(Evalue.get()))
        pop3.destroy()
    
    Cframe=Frame(pop3,width=500,height=200)
    Cframe.pack(anchor=CENTER)

    Clabel = Label(Cframe,text="Enter the variable where to be inserted")
    Clabel.grid(row=0,column=6,padx=20,pady=20)

    Evalue= Entry(Cframe,width=20)
    Evalue.grid(row=3,column=6,padx=20,pady=20)
    Evalue.insert(0,"Enter the variable")

    Cbutton=Button(Cframe,text='ENTER',width=10,command=INSERT)
    Cbutton.grid(row=6,column=6,padx=20,pady=20)

def OUTPUT():

    global pop3
    pop3=Toplevel(main)
    pop3.title("Create")
    pop3.geometry("500x200")
    
    def INSERT():

        source.append(output(Evalue.get()))
        pop3.destroy()
    
    Cframe=Frame(pop3,width=500,height=200)
    Cframe.pack(anchor=CENTER)

    Clabel = Label(Cframe,text="Enter the content to be displayed")
    Clabel.grid(row=0,column=6,padx=20,pady=20)

    Evalue= Entry(Cframe,width=20)
    Evalue.grid(row=3,column=6,padx=20,pady=20)
    Evalue.insert(0,"Enter message")

    Cbutton=Button(Cframe,text='ENTER',width=10,command=INSERT)
    Cbutton.grid(row=6,column=6,padx=20,pady=20)

# various tools as buttons
N=Button(top,text='NEW',width=10,height=1)
N.pack(side=LEFT,anchor=NW)
OP=Button(top,text='OPEN',width=10,height=1)
OP.pack(side=LEFT,anchor=NW)
S=Button(top,text='SAVE',width=10,height=1)
S.pack(side=LEFT,anchor=NW)
R=Button(top,text='RUN',width=10,height=1)
R.pack(side=LEFT,anchor=NW)
C=Button(top,text='CLEAR',width=10,height=1)
C.pack(side=LEFT,anchor=NW)


I=Button(tools,text='INPUT',width=10,command=INPUT)
I.grid(row=0,column=0)
O=Button(tools,text='OUTPUT',width=10,command=OUTPUT)
O.grid(row=1,column=0)
C=Button(tools,text='CREATE',width=10,command=CREATE)
C.grid(row=2,column=0)
A=Button(tools,text='ASSIGNMENT',width=10,command=ASSIGN)
A.grid(row=3,column=0)
I=Button(tools,text='INPUT',width=10,command=INPUT)
I.grid(row=4,column=0)
O=Button(tools,text='OUTPUT',width=10,command=OUTPUT)
O.grid(row=5,column=0)
IF=Button(tools,text='IF',width=10)
IF.grid(row=6,column=0)
F=Button(tools,text='FOR',width=10)
F.grid(row=7,column=0)
W=Button(tools,text='WHILE',width=10)
W.grid(row=8,column=0)
Ms=Frame(tools,bg="")
Ms.grid(row=9,column=0,padx=3,pady=3)
m1=Button(Ms,text='^',width=3)
m1.grid(row=0,column=1)
m2=Button(Ms,text='<',width=3)
m2.grid(row=1,column=0)
m3=Button(Ms,text='>',width=3)
m3.grid(row=1,column=2)
m4=Button(Ms,text='v',width=3)
m4.grid(row=2,column=1)

co=Label(tools,text='coordinates',width=10)
co.grid(row=14,column=0)


f=open('C:/Users/91964/Desktop/GITHUB/sem2/DS/project/new_project/main.cpp',"r")
data1=f.read()
g=open('C:/Users/91964/Desktop/GITHUB/sem2/DS/project/new_project/numbers.txt',"r")
data2=g.read()

num=Label(area2,width=2,height=800,bg='white',text=data2)
num.pack(side=LEFT,anchor=NW)

cpp=Label(area2,width=398,height=800,bg='grey',text=data1,justify="left")
cpp.pack(side=LEFT,anchor=NW,fill=BOTH)


# def dimension():
#     info=Label(tools,text=str(main.winfo_height()) + "x" + str(main.winfo_width()),bg="white")
#     info.grid(row=8,column=0)
# dimension()
def move(e):
    co.config(text="( x :" + str(e.x) + "y :" + str(e.y) + " )")

main.bind('<Motion>',move)
main.mainloop()








print(source)
