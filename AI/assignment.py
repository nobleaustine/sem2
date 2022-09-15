# -*- coding: utf-8 -*-
"""DLS.ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/1GYmEp-qFDV4WxLn8yQ1Yfx4-koJivL3U
"""

WHITE=1
GREY=0
BLACK=-1

class GRAPH:

  def __init__(self,M):
    self.Matrix=M
    self.N=M.shape[0]
    self.parent= [None for i in range(self.N)]
    self.color= [WHITE for i in range(self.N)]

  def getParent(self,index):
        return self.parent[index]

  def getColor(self,index):
      return self.color[index]
  
  def setParent(self,index,P):
      self.parent[index] = P
      
  def setColor(self,index,color):
      self.color[index] = color
      
  def getAdjacent(self,index):
      A=[]
      for i,v in enumerate(self.Matrix[index,:]):
          if v!=0:
              A.append(i)
      return A

class DLS:

  def __init__(self,Graph,MaxD,goal):
    self.G=Graph
    self.P=[]
    self.D=MaxD
    self.level=1
    self.Goal=goal
  
  def Traversal(self,S):
    self.P.append(S)
    self.G.setColor(S,BLACK)
    if S==self.Goal:
      return self.P
    elif len(self.P)==self.D:
      return False
    else:
      self.level=self.level+1
    for v in self.G.getAdjacent(S):
      if self.G.getColor(v) == WHITE:
        temp=self.Traversal(v)
        if temp==True:
          return self.P
        elif temp==self.P:
            return self.P 
        else:
          self.P.remove(v)
    return False  

  def printResult(self):
    for u in self.P:
      print(u,end=' ')
    print(' ')
          
    
class DFS:
  
  def __init__(self,Graph,Source):
    self.G=Graph
    self.S=Source
    self.result = []

  def traverse(self):
    for i in range(self.G.N):
      self.G.setColor(i,WHITE)
      self.G.setParent(i,None)
    self.G.setColor(self.S,GREY)
    self.DFS_visit(self.S)

  def DFS_visit(self,Y):
    self.result.append(Y)
    for v in self.G.getAdjacent(Y):
        if self.G.getColor(v) == WHITE:
          self.G.setColor(v,GREY)
          self.G.setParent(v,Y)
          self.DFS_visit(v)
    self.G.setColor(Y,BLACK)  
    

  def printResult(self):
    for u in self.result:
      print(u,end=' ')
    print(' ')
    
class IDDFS:

  def __init__(self,Graph,goal):
    self.G=Graph
    self.P=[]
    self.Goal=goal
  
  def Traversal(self,S,MaxD):
    for d in range(1,MaxD):
      self.G.parent= [None for i in range(self.G.N)]
      self.G.color= [WHITE for i in range(self.G.N)]
      self.P=[]
      if self.IDDFS_visit(S,d)==True:
        return True
    self.P.pop(0)
    return False
  
  def IDDFS_visit(self,node,d):
    
    self.P.append(node)
    self.G.setColor(node,BLACK)

    if node==self.Goal:
      return True
    elif len(self.P)==d:
      return False

    for v in self.G.getAdjacent(node):
      if self.G.getColor(v) == WHITE:
        if self.IDDFS_visit(v,d)==True:
          return True
        else:
          self.P.remove(v)
    return False

  def printPath(self):
    for u in self.P:
      print(u,end=' ')
    print(' ')            

import numpy as np

M = np.array([[0,1,1,0,0],
              [1,1,0,1,0],
              [1,0,0,1,1],
              [0,1,1,0,1],
              [0,0,1,1,0]])



G= GRAPH(M)
print("Choose from the following options : ")
print(" 1 : DFS")
print(" 2 : DLS")
print(" 3 : IDDFS")
option=int(input())

if(option==1):
  source= int(input("Enter the source node : "))
  search= DFS(G,source)
  search.traverse()
  print("Traversed path : ")
  search.printResult()
elif(option==2):
  source= int(input("Enter the source node : "))
  goal= int(input("Enter the goal node : "))
  MAX= int(input("Enter the limit : "))
  search= DLS(G,MAX,goal)
  search.Traversal(source)
  print("Traversed path : ")
  search.printResult()
else:
  source= int(input("Enter the source node : "))
  goal= int(input("Enter the goal node : "))
  MAX= int(input("Enter the limit : "))
  search= IDDFS(G,goal)
  search.Traversal(source,MAX)
  print("Traversed path : ")
  search.printPath()