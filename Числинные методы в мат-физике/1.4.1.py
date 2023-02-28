from math import sin, cos, pi, e
import numpy as np
M = N = 10
r = 0.1
h = 0.7
x = np.arange(-5, 5, r)
t = np.arange(0, 10, h)

func_1 = [sin(x[i]) for i in range(0, M)]
func_2 = [[(t[i] + x[j]**2) for j in range(0, N)] for i in range(M)]
diff_func_1 = [cos(x[i]) for i in range(0, M)]

u = np.zeros((N,M))
u[0] = [func_1[m] for m in range(0, M)]
for i in range(1, N):
    for j in range(0, N):
        u[i][j] = u[i-1][j] + r * (diff_func_1[j] + func_2[i-1][j])

F = [[((u[n+1][m] - u[n-1][m]) / (2*r))-((u[n][m+1] - u[n][m-1]) / (2*h)) for m in range(1, M-1)] for n in range(1, N-1)]

print(F)
##########################################################################################



o = r/h # число Куранта
a = pi/2 # 0..2PI
lmd = 1+1j*o*sin(a)-2*o**2*sin(a/2)**2
u = [[lmd**n*e**(1j*m*a) for m in range(0, N)] for n in range(0, N)]
lmd2 = (1-2*o**2*sin(a/2)**2)**2 + o**2*sin(a)**2 #лямбда квадрат по модулю
#print((abs(lmd))**2) # проверяем ормулы выше, встроеными операциями
F = [[((u[n+1][m] - u[n][m]) / r) - ((u[n][m+1] - u[n][m-1]) / 2*h) - r/2*h**2 * (u[n][m-1] - 2*u[n][m] + u[n][m+1]) for m in range(1, M-1)] for n in range(0, N-1)]
stability = (1-2*o**2*sin(a/2)**2)**2 + o**2*sin(a)**2
print(stability) # проверяем неотрицательна ли

##########################################################################################


o = r/h**2
b = 2*pi

lmd_a_b = 1 - 4 * o * sin(a/2)**2 - 4 * o * sin(b/2)**2
#print(1-8*o, "<=", lmd_a_b, "<=", 1) # проверка
#print(o, "<=", 1/4) # проверка условие устойчивости

import matplotlib.pyplot as plt
y = np.zeros((N,M))
count =0
for i in range(0,M):
    for j in range(0, M):
        y[i][j] = count
        count+=1
print(y)
plt.plot(u, y)
plt.show()