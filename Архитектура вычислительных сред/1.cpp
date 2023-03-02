#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void init_matrix(int** A, int n) {
    srand(time(0));
    for(int j=0; j<n; j++) {
        A[j] = new int[n];
        for(int k=0; k<n; k++) {
            A[j][k] = rand() % 100;
        }
    }
}

void multiply_matrices(int** A, int** B, int** C, int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int sum = 0;
            for(int k=0; k<n; k++) {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }
}

int main() {
    int sizes[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};
    const int num_sizes = sizeof(sizes) / sizeof(int);

    cout << "Matrix size\tTime taken (ms)\n";

    for(int i=0; i<num_sizes; i++) {
        int n = sizes[i];
        
        int** A = new int*[n];
        init_matrix(A, n);
        int** B = new int*[n];
        init_matrix(B, n);
        int** C = new int*[n];
        init_matrix(C, n);

        double start_time = clock();
        multiply_matrices(A, B, C, n);
        double end_time = clock();
        double time_taken = (end_time - start_time) / CLOCKS_PER_SEC * 1000;
    
        cout << n << "\t\t" << time_taken << endl;
    }

    return 0;
}
