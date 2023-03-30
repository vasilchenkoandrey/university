#include <iostream>
#include <mpi.h>

#define N 4
using namespace std;
int main(int argc, char** argv) {
    int rank, size, i, j, k;
    int A[N][N], B[N][N], C[N][N];
    int *sendbuf, *recvbuf;
    int sendcount, recvcount, displs;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                A[i][j] = i + j;
                B[i][j] = i - j;
            }
        }
    }

    sendcount = N * N / size;
    sendbuf = new int[sendcount];

    recvcount = sendcount;
    recvbuf = new int[recvcount * size];

    MPI_Scatter(A, sendcount, MPI_INT, sendbuf, sendcount, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(B, N * N, MPI_INT, 0, MPI_COMM_WORLD);

    for (i = 0; i < N / size; i++) {
        for (j = 0; j < N; j++) {
            C[i][j] = 0;
            for (k = 0; k < N; k++) {
                C[i][j] += sendbuf[i * N + k] * B[k][j];
            }
        }
    }

    displs = rank * recvcount;
    MPI_Gather(C, recvcount, MPI_INT, recvbuf, recvcount, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        cout << "Matrix A:" << endl;
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }

        cout << "Matrix B:" << endl;
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                cout << B[i][j] << " ";
            }
            cout << endl;
        }

        cout << "Matrix C:" << endl;
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                cout << recvbuf[i * N + j] << endl;
            }
            cout << endl;
        }
    }

    MPI_Finalize();
    return 0;
}