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
    int n = 500;
    
    int array_threads[] = {1, 2, 3, 4};
    const int num_threads = sizeof(array_threads) / sizeof(int);

    cout << "Num threads\tTime taken (ms)\n";
    
    // Initialize matrices
    int** A = new int*[n];
    init_matrix(A, n);
    
    int** B = new int*[n];
    init_matrix(B, n);
    
    int** C = new int*[n];
    init_matrix(C, n);
    
    vector<int> time_taken;
        
    for(int i=0; i<num_threads; i++) {

        // Multiply matrices and measure time
        double start_time = clock();

        // Number of cores available
        // const int num_threads = thread::hardware_concurrency();
        
        auto start = chrono::system_clock::now();
        vector<thread> threads;
        for(int j=0; j<array_threads[i]; j++) {
            const int block_size = n / array_threads[i];
            int start = j * block_size;
            int end = (j == array_threads[i] - 1) ? n : (j + 1) * block_size;
            threads.emplace_back(multiply_matrices, A, B, C, n, start, end);
        }

        for(auto& thread : threads) {
            thread.join();
        }

        double end_time = clock();
        auto end = chrono::system_clock::now();
        chrono::duration<double> elapsed_seconds = end - start;
     
        cout << array_threads[i] << "\t\t" << ((end_time - start_time) / CLOCKS_PER_SEC) << "  " << elapsed_seconds.count() << endl;
    }

    return 0;
}
