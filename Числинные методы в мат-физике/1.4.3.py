from math import sin, cos, pi, e
import numpy as np

N = M = L = 10
r = 0.1
h = 0.7
o = r/h**2
a = pi/2
b = 2*pi

lmd_a_b = 1 - 4 * o * sin(a/2)**2 - 4 * o * sin(b/2)**2
print(1-8*o, "<=", lmd_a_b, "<=", 1)
print(o, "<=", 1/4)