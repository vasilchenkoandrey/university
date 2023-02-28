import numpy as np
import matplotlib.pyplot as plt

# Интерполяция многочлена
def lagrange(x,y,t):
    L=0
    for j in range(len(y)):
        p=1
        for i in range(len(x)):
            if i==j:p=p*1   
            else:p=p*(t-x[i])/(x[j]-x[i])
        L=L+y[j]*p
    return L

x=np.array([-1, -0.8, -0.6, -0.4, -0.2, 0, 0.2, 0.4, 0.6, 0.8, 1]) # x
y=[(1/(1 +21*pow(x[i],2))) for i in range(len(x))] # f(x)
nls=100 # количество разбиений (сглаживание)
xnew=np.linspace(np.min(x),np.max(x),nls) # равномерное разбиение
ynew=[lagrange(x,y,i) for i in xnew] # L(x)

plt.plot(x,y,xnew,ynew) # рисуем график по точкам
plt.title('Интерполяционный многочлен Лагранжа. \n Аппроксимация функции многочленом.') # оглавление программы
plt.legend(['f(x)','L(x)']) # легенда
plt.grid(True) # решетка
plt.show() # вызываем окно с графиком
