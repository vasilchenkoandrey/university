import numpy as np
import matplotlib.pyplot as plt
from math import cos, pi

def newton(x,y,t):
    N = 0
    for j in range(n):
        l = 1
        for i in range(n):
            if (i != j):
                l = l*(t-x[i])/(x[j]-x[i])
                lx.append(y[j]*l)
        N = N + y[j] * l
    return N


x = [-1,-0.5,0,0.5,1]
y1=[(abs(x[i])) for i in range(len(x))]
y2=[(x[i]**3) for i in range(len(x))]
y3=[(cos(pi*x[i]/2)) for i in range(len(x))]
n = len(x)
nls=500 # 17, 41
lx=[]
xnew=np.linspace(np.min(x),np.max(x),nls)
y1new=[newton(x,y1,i) for i in xnew]
y2new=[newton(x,y2,i) for i in xnew]
y3new=[newton(x,y3,i) for i in xnew]


print(" ________________________________________________________________________________")
print("| {:<6} || {:<8} | {:<8} || {:<8} | {:<8} || {:<8} | {:<8} |" .format("X[i]", "|x|", "N(x)", "x^3", "N(x)", "cos(pi*x/2)", "N(x)"))
print("|--------||----------|----------||----------|----------||-------------|----------|")
for i in range(len(y1new)):
    print("| {:<6.3f} || {:<8.5f} | {:<8.5f} || {:<8.5f} | {:<8.5f} || {:<11.5f} | {:<8.5f} |" .format(xnew[i], abs(xnew[i]), y1new[i], xnew[i]**3, y2new[i], cos(pi*xnew[i]/2), y3new[i]))
print("|________________________________________________________________________________|")

print("Интерполяционный процесс для функции f интерполянтом Ln называется сходящимся на I := ⟨a, b⟩, если для любого x ∈ I выполняется |f(x) − Ln(x, f, Xn)|→0, n→∞")

plt.plot(x,y3, xnew, y3new)
plt.title('Интерполяционный многочлен в форме Ньютона') # оглавление программы
plt.legend(['cos(pi*x/2)','N(x)']) # легенда
plt.grid(1)
plt.show()