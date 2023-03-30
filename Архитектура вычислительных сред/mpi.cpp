#include <iostream>
#include <mpi.h>

using namespace std;

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int l = 0, r = 99999;

    if (rank == 0) {
        for (int i = 1; i < size; ++i) {
            MPI_Send(&l, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
            MPI_Send(&r, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
        }
    } else {

        MPI_Recv(&l, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(&r, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }

    int count = 0;
    for (int i = l; i <= r; ++i) {
        if (i % 11 == 0 || i % 13 == 0 || i % 17 == 0) {
            ++count;
        }
    }

    int sum;
    MPI_Reduce(&count, &sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    if (rank == 0) {
        cout << sum << endl;
    }

    MPI_Finalize();
    return 0;
}