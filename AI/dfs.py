# -*- coding: utf-8 -*-
"""DFS.ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/1NciijRtas6mH6cpIeZQc9uVZu5hPJ2Po
"""

WHITE=1
GREY=0
BLACK=-1

class GRAPH:

  def __init__(self,M):
    self.Matrix=M
    self.N=M.shape[0]
    self.parent= [None for i in range(self.N)]
    self.color= [None for i in range(self.N)]

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

import numpy as np
M = np.array([[0,1,1,1,0,0,0,0],
              [1,0,0,0,1,1,0,0],
              [1,0,0,0,0,0,1,1],
              [1,0,0,0,0,0,0,1],
              [0,1,0,0,0,1,0,0],
              [0,1,0,0,1,0,1,0],
              [0,0,1,0,0,1,0,0],
              [0,0,1,1,0,0,0,0]])

Z= np.array([[0,1,1,0,0],
             [1,1,0,1,0],
             [1,0,0,1,1],
             [0,1,1,0,1],
             [0,0,1,1,0]])

G = GRAPH(Z)

#G = GRAPH(M)
search = DFS(G,0)
search.traverse()
search.printResult()
