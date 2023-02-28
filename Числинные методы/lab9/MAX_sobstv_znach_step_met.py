import numpy as np
A = np.array([[2,1,-1],[1,-2,1],[3,1,1]])
r = [0]*20000
r[0] = np.array([[1],[1],[1]])
L = 1
LTemp = 0
k = 0
while 1:
    print("==================================================")
    r[k+1] = A.dot(r[k])
    L = r[k+1][0] / r[k][0]
    if abs(L - LTemp) > 0.001:
        print('k =',k+1)
        print('a) {} {} {}' .format(r[k][0],r[k][1],r[k][2]))
        print('b)','L =',r[k+1][0],'/',r[k][0],'=',L)
        print('c)','Lmbda =', L)
        print('d)','| L',k+1,'- L',k,'| =',L,'-',LTemp,'=',L - LTemp)
        LTemp = L
        k+=1
    else: 
        print('k =',k+1)
        print('a) {} {} {}' .format(r[k][0],r[k][1],r[k][2]))
        print('b)','L =',r[k+1][0],'/',r[k][0],'=',L)
        print('c)','Lmbda =', L)
        print('d)','| L',k+1,'- L',k,'| =',L,'-',LTemp,'=',L - LTemp)
        break


    