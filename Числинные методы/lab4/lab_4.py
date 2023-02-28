from scipy.interpolate import interp1d
import matplotlib.pyplot as plt
import numpy as np

n = 4 #4 10
x = np.linspace(-1, 1, n+1)
y = np.array([1/(1+21*x[i]**2) for i in range(len(x))])

xnew = np.linspace(-1, 1, 49) #49 101
ynew = np.array([1/(1+21*xnew[i]**2) for i in range(len(xnew))])

f = interp1d(xnew, ynew)
f2 = interp1d(x, y, kind='cubic')

print(f2(xnew))
 
plt.plot(x, y, 'o', xnew, ynew, '--', xnew, f2(xnew), '-')
plt.legend(['Точки', 'Функция', 'Кубик'], loc='best')
plt.show()