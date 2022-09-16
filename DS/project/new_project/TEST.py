# list for inputting objects of all classes
source = []

# class for creating a variable of particular data type
class create:

	def __init__(self,dtype,name,value=None):
		self.dtype = dtype
		self.name = name
		self.value = value

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

# part to move with mouse

def move(e):
    my_label.config(text="Coordinates : x:" + str(e.x) + " y:" + str(e.y))



# part to control the arrow keys
def left(event):
	x = -10
	y = 0
    
	Cgraphic.move(start,x,y)
	Cgraphic.move(sname,x,y)

def right(event):
	x = 10
	y = 0
    
	Cgraphic.move(start,x,y)
	Cgraphic.move(sname,x,y)

def up(event):
	x = 0
	y = -10
    
	Cgraphic.move(start,x,y)
	Cgraphic.move(sname,x,y)

def dow(event):
	x = 0
	y = 10
    
	Cgraphic.move(start,x,y)
	Cgraphic.move(sname,x,y)

# graphical interface
from tkinter import *

# main window for diplaying program
main = Tk(None,None,'project',1)
main.state('zoomed')

# main heading as C++ GRAPHICS 
text= Label(main, font=('Times New Roman',15,'bold'),text="C++ GRAPHICS",bg="#2B55A9")
text.pack()

# frame for placing tools 
tools=Frame(main,bg="red")
tools.pack(side=LEFT,anchor=NW)

# frame for displaying the flowchart  
graphic=Frame(main,bg="green")
graphic.pack(side=LEFT,anchor=NW)

# frame for displaying code
code=Frame(main,bg="blue")
code.pack(side=LEFT,anchor=NW)

# label to display heading of graphics section
hgraphic=Label(graphic,font=('Times New Roman',15,'bold'),text="GRAPHIC",bg="#2B55A9")
hgraphic.pack()

# contents within tools frame
# heading for tools frame as TOOLS
htools=Label(tools,font=('Times New Roman',15,'bold'),text="TOOLS",bg="#2B55A9")
htools.pack()

# functions called while using tools buttons
def CREATE():

    global pop1
    pop1=Toplevel(main)
    pop1.title("Create")
    pop1.geometry("500x200")
    
    def INSERT():

        source.append(create(Edtype.get(),Ename.get(),Evalue.get()))
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

def move(event):
    my_label.config(text="Coordinate : x :" + str(event.x) + " y :" + str(event.y))
    # start=Cgraphic.create_oval(event.x,event.y,event.x + 50,event.y + 50)
    a=100
    b=100
    c=event.x -a 
    d=event.y -b
    Cgraphic.move(start,c,d)
    Cgraphic.move(sname,c,d)

# various tools as buttons
C=Button(tools,text='CREATE',width=25,command=CREATE)
C.pack()
A=Button(tools,text='ASSIGNMENT',width=25,command=ASSIGN)
A.pack()
I=Button(tools,text='INPUT',width=25,command=INPUT)
I.pack()
O=Button(tools,text='OUTPUT',width=25,command=OUTPUT)
O.pack()
IF=Button(tools,text='IF',width=25)
IF.pack()
F=Button(tools,text='FOR',width=25)
F.pack()
W=Button(tools,text='WHILE',width=25)
W.pack()

my_label=Label(tools,text="a")
my_label.pack()

Cgraphic=Canvas(graphic,width=600,height=800,bg="white")
Cgraphic.pack(side=LEFT,anchor=NW)



start=Cgraphic.create_oval(50,50,100,100)
sname=Cgraphic.create_text(75,75,text="START")
Cgraphic.create_line(75,100,75,150)

 
# main.bind("<Left>",left)
# main.bind("<Right>",right)
# main.bind("<Up>",up)
# main.bind("<Down>",dow)
main.bind('<B1-Motion>',move)

f=open("main.cpp","r")
data=f.read()
hcode=Label(code,font=('Times New Roman',15,'bold'),text="CODE",bg="#2B55A9")
hcode.pack()
Ccode=Label(code,width=600,height=800,font=('Times New Roman',12),bg='grey',text=data)
Ccode.pack(side=LEFT,anchor=NW)

main.mainloop()

print(source)
