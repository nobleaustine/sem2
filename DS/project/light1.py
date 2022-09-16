import itertools 

# room=[(5,2),(1,4),(-3,2),(-2,-2),(2,-1)]
# demi=[(1,4),(-3,2),(-2,-2),(2,-1),(5,2)]
room=[(0,0),(-2,1),(-3,5),(0,6),(3,4),(2,1)]
demi=[(-2,1),(-3,5),(0,6),(3,4),(2,1),(0,0)]


def area():
    A=0
    for (i,j) in zip(room,demi):
           A=A+(i[0]*j[1]-i[1]*j[0])
    A=A/2
    A=6*A
    return A

def centre(A):
    X=0
    Y=0
    for (i,j) in zip(room,demi):
           X=X+(i[0] + j[0])*(i[0]*j[1]-i[1]*j[0])
           Y=Y+(i[1] + j[1])*(i[0]*j[1]-i[1]*j[0])
    X=X/A
    Y=Y/A
    print(X,Y)
a=area()
print(a)
centre(a)





