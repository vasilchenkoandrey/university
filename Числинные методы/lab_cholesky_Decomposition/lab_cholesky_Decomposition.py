#!/usr/bin/env python
# coding: utf-8

# # РАЗЛОЖЕНИЕ ХОЛЕЦКОГО

# In[164]:


from IPython.display import Latex


# Разложение Холецкого симметричной положительно-определенной матрицы $A$ — это разложение вида $A=LL^T $ , где $L$ — нижняя треугольная матрица с действительными и положительными диагональными элементами, а L$^T$ обозначает сопряженную транспонированность $L$

# #### Схема реализации последовательного алгоритма
# 
# ![image.png](attachment:image.png)
# После этого (если i<n) происходит переход к шагу 3 с большим i.

# In[165]:


from math import sqrt
import numpy

def Cholesky_Decomposition(matrix):
    n = len(matrix)
    L = numpy.array([[0 for x in range(n)] for y in range(n)])
    # Разложение матрицы в нижнюю треугольную матрицу (L)
    for i in range(n): 
        for j in range(i + 1): 
            sum1 = 0
            
            # sum1 - суммировние для диагностики
            if (j == i): 
                for k in range(j):
                    sum1 += pow(L[j][k], 2)
                L[j][j] = int(sqrt(matrix[j][j] - sum1))
            else:
                
                # Оценка L(i, j) используя L(j, j)
                for k in range(j):
                    sum1 += (L[i][k] *L[j][k])
                if(L[j][j] > 0):
                    L[i][j] = int((matrix[i][j] - sum1) / L[j][j])
    return L

A = [[81, -45, 45],
     [-45, 50, -15],
     [45, -15, 38]]
b = [531, -460, 193]

L = Cholesky_Decomposition(A)
LT = Cholesky_Decomposition(A).T
y = numpy.linalg.solve(L, b) # Ly=b
x = numpy.linalg.solve(LT, y) # L^Tx=y


# Исходная матрица:
# $A=\begin{pmatrix} 81 & -45 & 45 \\ -45 & 50 & -15 \\ 45 & -15 & 38\end{pmatrix}; \ \  $
# $b=\begin{pmatrix} 531 \\ -460 \\ 193 \end{pmatrix}$
# $$$$
# Разложение Холецкого: $A=LL^T=\begin{pmatrix} 9 & 0 & 0 \\ -5 & 5 & 0 \\ 5 & 2 & 3\end{pmatrix}*\begin{pmatrix} 9 & -5 & 5 \\ 0 & 5 & 2 \\ 0 & 0 & 3\end{pmatrix}$
# $$$$
# Решением системы $Ly=b$ является вектор $y=\begin{pmatrix} 59 \\ -33 \\ -12 \end{pmatrix}$
# $$$$
# Решением системы $L^Tx=y$ является вектор $x=\begin{pmatrix} 5 \\ -5 \\ -4 \end{pmatrix}$
# $$$$
# Ответ: $X_1=6; \ \ \ X_2=-5; \ \ \ X_3=-4$
# 
# 
# 
# 

# 
# 
