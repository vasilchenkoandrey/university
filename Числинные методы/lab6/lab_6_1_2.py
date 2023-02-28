from math import sin, pi, sqrt, pow
import numpy as np

def f(x):
    a=0.1
    if x != 0: out=1/(sqrt(1-a*a*sin(x)*sin(x)*x))
    else: out=1
    return out

def simpson(a,b,eps):
    I=eps+1
    I1=0
    N=2
    while (N<=4) or abs(I1-I)>eps:
        summa2=0; summa4=0; summa=0
        h=(b-a)/(2*N)
        for i in range(1, 2*N-1, 2):
            summa4+=f(a+h*i)
            summa2+=f(a+h*(i+1))
        summa=f(a)+4*summa4+2*summa2-f(b)
        I=I1
        I1=(h/3)*summa
        N*=2
    return I1

a=0
b=1
eps=0.001
bArr = np.linspace(0, pi/2, 10)
for i in range(len(bArr)):
    print("| {:<6.3} | {:<20} |" .format(bArr[i], simpson(a,bArr[i],eps)))

#Вывод: Для каждого ε существует такое h, что будет выполняться условие Рунге.









# print(" --------------------------------------")
# print("| a =", a,"|","| b =", b,"|", "| f(x)=(ch(x)-1)/x |",)
# print(" --------------------------------------")

# print(" ___________________________________")
# print("| {:<15} | {:<15} |" .format("X[i]", "I[i]"))
# print("|-----------------|-----------------|")
# for i in range(len(x)):
#     print("| {:<15.10f} | {:<15.10f} |" .format(x[i], I[i]))
# print("|___________________________________|")
# print("| Sn =", Sn, '         |')
# print("|-----------------------------------|")
# print("| eps =", eps, '        |')
# print("|___________________________________|")