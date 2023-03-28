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
    int n = 1000;
    int K = 50;
    
    cout << "Num threads\tTime taken (ms)\n";
    
    // Initialize matrices
    int** A = new int*[n];
    init_matrix(A, n);
    
    int** B = new int*[n];
    init_matrix(B, n);
    
    int** C = new int*[n];
    init_matrix(C, n);
    
    for(int num_threads=1; num_threads<=K; num_threads++) {
        
        // Multiply matrices and measure time
        auto start = std::chrono::system_clock::now();
        vector<thread> threads;
        for(int i=0; i<num_threads; i++) {
            const int block_size = n / num_threads;
            int start = i * block_size;
            int end = (i == num_threads - 1) ? n : (i + 1) * block_size;
            threads.emplace_back(multiply_matrices, A, B, C, n, start, end);
        }

        for(auto& thread : threads) {
            thread.join();
        }

        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
     
        cout << num_threads << "\t\t" << elapsed_seconds.count() << endl;
    }
    return 0;
}
