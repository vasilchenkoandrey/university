#!/usr/bin/env python
# coding: utf-8

# # МЕТОД РУНГЕ – КУТТА РЕШЕНИЯ ЗАДАЧИ КОШИ ДЛЯ ОБЫКНОВЕННОГО ДИФФЕРЕНЦИАЛЬНОГО УРАВНЕНИЯ

# In[136]:


from IPython.display import Latex


# Требуется найти приближенное решение уравнения: $y'=f(x,y), \ x∈[x_0,X],$
# при заданном начальном условии: $y(x_0)=y_0.$ 

# In[209]:


from numpy import array, sin, e
def dydx(x, y):
    return (1 + sin(2*x) * e**(-x * (1 + x)) + 2 * (2 - x) * y) 

def rungeKutta(x0, y0, X, h):
    n = (int)((X - x0)/h)
    y = y0
    arrk1 = zeros(n)
    print("{:<4} {:<6} {:<11} {:<11} {:<11} {:<11} {:<11}" .format("n","x0","y","k1","k2","k3","k4"))
    for i in range(0, n + 1):
        k1 = h * dydx(x0, y)
        k2 = h * dydx(x0 + 0.5 * h, y + 0.5 * k1)
        k3 = h * dydx(x0 + 0.5 * h, y + 0.5 * k2)
        k4 = h * dydx(x0 + h, y + k3)
        print("{:<4d} {:<6.1f} {:<11f} {:<11f} {:<11f} {:<11f} {:<11f}" .format(i,x0,y,k1,k2,k3,k4))
        y = y + (1.0 / 6.0)*(k1 + 2 * k2 + 2 * k3 + k4)
        x0 = x0 + h
    #return y

x0 = 1
y = 10
X = 6
h = 0.1


# $$f(x,y) = (a + b(x)) \cdot e^{c(x)} + 2 \cdot (2 - x) \cdot y$$
# $$a=1$$
# $$b=sin(2x)$$
# $$c=-x \cdot (1 + x)$$
# $$h=0.1$$
# 

# In[210]:


rungeKutta(x0, y, X, h)


# In[246]:




