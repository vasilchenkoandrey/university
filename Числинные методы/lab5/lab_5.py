import numpy as np
import numpy.linalg as la
from math import log, exp
import matplotlib.pyplot as plt

x=[2,3,4,5,6]; y=[1,4,1,5,2]

xDegree = []; xDegreeSumm = []
for j in (0,2,3,4):
    sumTemp=0
    for i in range(len(x)):
        xDegree.append(x[i]**j)
        sumTemp += x[i]**j
    xDegreeSumm.append(sumTemp)
xDegreeSumm.insert(1,sum(x))

# Quadratic function (quad)
n=3
quadA = np.zeros((n,n))
for i in range(n):
    for j in range(n):
        quadA[i][j]=xDegreeSumm[j+i]
quadAInvers=la.inv(quadA)
quadB=np.array([sum(y[i]*(x[i]**j) for i in range(len(y))) for j in range(n)])
quadxnew = np.dot(quadAInvers, quadB)
quadFunction=np.array([quadxnew[0]+quadxnew[1]*x[i]+quadxnew[2]*x[i]**2 for i in range(len(x))])

# Linear function (line)
n=2
lineA = np.zeros((n,n))
for i in range(n):
    for j in range(n):
        lineA[i][j]=xDegreeSumm[j+i]
lineAInvers=la.inv(lineA)
lineB=np.array([sum(y[i]*(x[i]**j) for i in range(len(y))) for j in range(n)])
linexnew = np.dot(lineAInvers, lineB)
lineFunction=np.array([linexnew[0]+linexnew[1]*x[i] for i in range(len(x))])

# Power function (pow)
powLnx=np.array([log(x[i]) for i in range(len(x))])
powLny=np.array([log(y[i]) for i in range(len(x))])
powLnx2=np.array([log(x[i])**2 for i in range(len(x))])
powLnxLny=np.array([powLnx[i]*powLny[i] for i in range(len(x))])
i=len(x)
powB=(sum(powLnx)*sum(powLny)-sum(powLnxLny)*i)/(sum(powLnx)**2-sum(powLnx2)*i) # minus
powLna=(sum(powLny)-sum(powLnx)*powB)/i
powa=exp(powLna)
powFunction=np.array([powa*x[i]**powB for i in range(len(x))])

plt.title("Метод наименьших квадратов")
plt.grid(True)
plt.scatter(x,quadFunction); plt.plot(x,quadFunction, label='Квадратичная')
plt.scatter(x,lineFunction); plt.plot(x,lineFunction, label='Линейная')
plt.scatter(x,powFunction); plt.plot(x,powFunction, label='Степенная')
plt.legend()
plt.show()