#include <iostream>
#include <thread>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

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

void multiply_matrices(int** A, int** B, int** C, int n, int start, int end) {
    for(int i=start; i<end; i++) {
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
    const int sizes[] = {10, 20, 50, 100, 200, 500, 1000};
    const int num_sizes = sizeof(sizes) / sizeof(int);

    cout << "Matrix Size\tTime taken (ms)\n";
    
    for(int i=0; i<num_sizes; i++) {
        const int n = sizes[i];
        
        int** A = new int*[n];
        init_matrix(A, n);
        
        int** B = new int*[n];
        init_matrix(B, n);
        
        int** C = new int*[n];
        for(int j=0; j<n; j++) {
            C[j] = new int[n];
        }

        vector<thread> threads;
        auto start = std::chrono::system_clock::now();
        for(int i=0; i<n; i++) {
            threads.emplace_back(multiply_matrices, A, B, C, n, i, i+1);
        }
        for(auto& thread : threads) {
            thread.join();
        }
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;

        cout << n << "x" << n << "\t\t" << elapsed_seconds.count() << endl;
    }

    return 0;
}
