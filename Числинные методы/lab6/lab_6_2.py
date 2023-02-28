from math import sin, pi, sqrt, pow

def f(x):
    a=0.1
    if x != 0: out=1/(sqrt(1-a*a*sin(x)*sin(x)*x))
    else: out=1
    return out

def NewtonCotes(a, b, Degree, Ndivisions):
    koef=[[1,0,0,0,0,0,0,0,0,0], #Коэф Ньютона-Котеса
          [1,1,0,0,0,0,0,0,0,0],
          [1,4,1,0,0,0,0,0,0,0],
          [1,3,3,1,0,0,0,0,0,0],
          [7,32,12,32,7,0,0,0,0,0],
          [19,75,50,50,75,19,0,0,0,0],
          [41,216,27,272,27,216,41,0,0,0],
          [751,3577,1323,2989,2989,1323,3577,751,0,0],
          [989,5888,-928,10496,-4540,10496,-928,5888,989,0],
          [2857,15741,1080,19344,5778,5778,19344,1080,15741,2857]]
    mltp=[1,1.0/2,1.0/3,3.0/8,2.0/45,5.0/288,1.0/140,7.0/17280,4.0/14175,9.0/89600]
 
    if ((Degree<0) or (Degree>9)): print("Неправильная степень")
    if (a>=b): print("Неправильный сегмент")
    if (Ndivisions<1): Ndivisions = 1
 
    h=(b-a)/(Degree*Ndivisions)
    Sum=0
    for j in range(0, Ndivisions-1):
        PartSum=0
        for i in range(0, Degree):
            PartSum+= koef[Degree][i]*f(a + (i+j*Degree) * h )
        Sum+= mltp[Degree]*PartSum*h
    return Sum


a=0
b=pi
Degree=1
n=7
h=(b-a)/n
print(NewtonCotes(a, b, Degree, n))
#Вывод: при увеличении количества n результаты вычислений становятся более точными.
