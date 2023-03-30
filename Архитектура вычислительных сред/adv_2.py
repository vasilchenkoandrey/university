import multiprocessing as mp

def matrix_multiply(A, B, result, i, j):
    row = len(A[0])
    value = 0
    for k in range(row):
        value += A[i][k] * B[k][j]
    result[i][j] = value

def multiply_matrices(A, B):
    row_A = len(A)
    col_B = len(B[0])
    result = [[0] * col_B for _ in range(row_A)]

    processes = []
    for i in range(row_A):
        for j in range(col_B):
            process = mp.Process(target=matrix_multiply, args=(A, B, result, i, j))
            process.start()
            processes.append(process)

    for process in processes:
        process.join()

    return result

A = [[2, 5, 7], [8, 9, 44], [3, 2, 1]]
B = [[15, 8, 5], [3, 14, 85], [1, 27, 1]]
result = multiply_matrices(A, B)
print(result)