from sympy import *
A = Matrix([[7,4,6],[2,5,-4],[1,-1,3]])
print(A,"\n",1 / A.det() * (A.cofactor_matrix().T))








# По фрмуле Ai = 1/det(A) * adj(A)
# Адъюктивная матрица (сопряженная) получается путем транспонирования кофакторной матрицы
# Кофакторная матрица - строится путем замены всех элементов матрицы А на их алгебраическое дополнение.


