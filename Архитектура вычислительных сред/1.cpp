#include <iostream>
#include <thread>
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
    int sizes[] = {100, 200, 300, 400, 500, 600, 700};
    const int num_sizes = sizeof(sizes) / sizeof(int);

    cout << "Matrix size\tTime taken (ms)\n";

    for(int i=0; i<num_sizes; i++) {
        
        int n = sizes[i];
        
        // Initialize matrices
        int** A = new int*[n];
        init_matrix(A, n);
        
        int** B = new int*[n];
        init_matrix(B, n);
        
        int** C = new int*[n];
        init_matrix(C, n);
        
        vector<int> time_taken;
            
        for(int test=0; test<=3; test++) {
    
            // Multiply matrices and measure time
            double start_time = clock();
    
            // Number of cores available
            const int num_threads = thread::hardware_concurrency();
            const int block_size = n / num_threads;
    
            vector<thread> threads;
            for(int i=0; i<num_threads; i++) {
                int start = i * block_size;
                int end = (i == num_threads - 1) ? n : (i + 1) * block_size;
                threads.emplace_back(multiply_matrices, A, B, C, n, start, end);
            }
    
            for(auto& thread : threads) {
                thread.join();
            }
    
            double end_time = clock();
            time_taken.emplace_back((end_time - start_time) / CLOCKS_PER_SEC * 1000);
        }
        cout << n << "\t\t" << time_taken[0] << "\t" << time_taken[1] << "\t" << time_taken[2] << "\t" << endl;
    }

    return 0;
}