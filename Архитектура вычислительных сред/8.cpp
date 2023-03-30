#include <iostream>
#include <queue>
#include <mutex>
#include <thread>

using namespace std;

queue<int> inputQueue;
mutex queueMutex;

void input() {
    int num;
    do {
        cin >> num;
        lock_guard<mutex> lock(queueMutex);
        inputQueue.push(num);
    } while (num != -1);
}


void calculate() {
    while (true) {
        lock_guard<mutex> lock(queueMutex);
        if (inputQueue.empty()) { 
            continue;
        }
        int num = inputQueue.front();
        inputQueue.pop();
        if (num == -1) {
            break;
        }
        cout << "Factors of " << num << ": ";
        for (int i = 2; i <= num; i++) {
            while (num % i == 0) {
                cout << i << " ";
                num /= i;
            }
        }
        cout << endl;
    }
}

int main() {
    thread inputThread(input);
    thread calculateThread(calculate);
    inputThread.join();
    calculateThread.join();
    return 0;
}