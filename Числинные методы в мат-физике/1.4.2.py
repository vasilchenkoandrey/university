from math import sin, cos, pi, e
import numpy as np

N = M = 10
r = 0.3
h = 0.7
o = r/h
a = pi/2
lmd = 1+1j*o*sin(a)-2*o**2*sin(a/2)**2
u = [[lmd**n*e**(1j*m*a) for m in range(0, N)] for n in range(0, N)]
lmd2 = (1-2*o**2*sin(a/2)**2*a)
F = [[((u[n+1][m] - u[n][m]) / r) - ((u[n][m+1] - u[n][m-1]) / 2*h) - r/2*h**2 * (u[n][m-1] - 2*u[n][m] + u[n][m+1]) for m in range(1, M-1)] for n in range(0, N-1)]
stability = (1-2*o**2*sin(a/2)**2)**2 + o**2*sin(a)**2
