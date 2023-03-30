

import pycuda.autoinit
import pycuda.driver as drv
import numpy as np
from pycuda.compiler import SourceModule

mod = SourceModule("""
    __global__ void multiply_matrices(int *a, int *b, int *c, int n)
    {
        int row = blockIdx.y * blockDim.y + threadIdx.y;
        int col = blockIdx.x * blockDim.x + threadIdx.x;
        int sum = 0;
        if (col < n && row < n) {
            for (int i = 0; i < n; ++i) {
                sum += a[row * n + i] * b[i * n + col];
            }
            c[row * n + col] = sum;
        }
    }
""")

multiply_matrices = mod.get_function("multiply_matrices")

n = 1024
a = np.random.randint(10, size=(n, n)).astype(np.int32)
b = np.random.randint(10, size=(n, n)).astype(np.int32)
c = np.zeros((n, n)).astype(np.int32)

block_size = (16, 16, 1)
grid_size = ((n + block_size[0] - 1) // block_size[0], (n + block_size[1] - 1) // block_size[1], 1)

multiply_matrices(drv.In(a), drv.In(b), drv.Out(c), np.int32(n), block=block_size, grid=grid_size)

print(c)