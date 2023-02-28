import numpy as np
import numpy.linalg as la

x=[2,3,4,5,6]; y=[1,4,1,5,2]
xDegree = []; xDegreeSumm = []
for j in (0,2,3,4):
    sumTemp=0
    for i in range(len(x)):
        xDegree.append(x[i]**j)
        sumTemp += x[i]**j
    xDegreeSumm.append(sumTemp)
xDegreeSumm.insert(1,sum(x))
print(xDegree)
print(xDegreeSumm)
#Метод найменьших квадратов (квадратич.) (msqq)
msqqA = [[0,0,0],[0,0,0],[0,0,0]]
for i in range(3):
    for j in range(3):
        msqqA[i][j]=xDegreeSumm[j+i]
msqqAInvers=la.inv(msqqA)

b=[]
temp=0
b.append(sum(y))
for i in range(len(x)):
    temp+=x[i]*y[i]
b.append(temp)
temp=0
for i in range(len(x)):
    temp+=xDegree[i+len(x)]*y[i]
b.append(temp)
xnew=[]
xnew = b.dot(msqqAInvers)
print(xnew)

