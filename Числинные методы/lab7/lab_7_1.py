def epsilon(eps=1):
    while 1+eps > 1: eps/=2
    return eps*2

def gauss_jordan(A, eps = epsilon()):
  (col, row) = (len(A), len(A[0]))
  for y in range(0,col):
    maxrow = y
    for y2 in range(y+1, col):    # Find max
      if abs(A[y2][y]) > abs(A[maxrow][y]):
        maxrow = y2
    (A[y], A[maxrow]) = (A[maxrow], A[y])
    if abs(A[y][y]) <= eps:     # Singular?
      return False
    for y2 in range(y+1, col):    # Eliminate column y
      c = A[y2][y] / A[y][y]
      for x in range(y, row):
        A[y2][x] -= A[y][x] * c
  for y in range(col-1, 0-1, -1): # Backsubstitute
    c  = A[y][y]
    for y2 in range(0,y):
      for x in range(row-1, y-1, -1):
        A[y2][x] -=  A[y][x] * A[y2][y] / c
    A[y][y] /= c
    for x in range(col, row):       # Normalize row y   
      A[y][x] /= c
  return True

A = [[5,4,-0.5,1.5],
    [4,-6.8,0.4,-3],
    [1,2,0.5,1.5]]

if gauss_jordan(A):
  for i in A:
    print(i)
