import math

L=0
x0=0.1
x = [-1,-0.5,0,0.5,1]
y = [0.1,0.2,0.3,0.4,0.5]
for i in range(len(y)):
    p1=1
    p2=1
    for j in range(len(x)):
        if i==j:
            p1=p1*1
            p2=p2*1
        else:
            p1=p1*(x0-x[j])
            p2=p2*(x[i]-x[j])
    L=L+y[i]*p1/p2
print("L(",i,")=",L)
