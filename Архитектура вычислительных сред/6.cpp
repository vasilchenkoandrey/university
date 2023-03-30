#include <iostream>
#include <cmath>
#include <thread>
#include <mutex>

using namespace std;

double f(double x) {
    return sqrt(1 - x * x);
}

double simpson(double a, double b) {
    double c = (a + b) / 2.0;
    return (f(a) + 4 * f(c) + f(b)) * (b - a) / 6.0;
}

double adaptive_simpson(double a, double b, double eps, double whole, mutex& mtx, int& running_threads) {
    double c = (a + b) / 2.0;
    double left, right;
    thread left_thread, right_thread;

    {
        lock_guard<mutex> guard(mtx);
        running_threads += 2;
        cout << "Number of running threads: " << running_threads << endl;
    }

    left_thread = thread([&]() {
        left = simpson(a, c);
        lock_guard<mutex> guard(mtx);
        running_threads--;
    });
    right_thread = thread([&]() {
        right = simpson(c, b);
        lock_guard<mutex> guard(mtx);
        running_threads--;
    });

    left_thread.join();
    right_thread.join();

    double result = left + right;

    if (fabs(result - whole) <= 15 * eps) {
        return result + (result - whole) / 15.0;
    } else {
        return adaptive_simpson(a, c, eps / 2.0, left, mtx, running_threads) +
               adaptive_simpson(c, b, eps / 2.0, right, mtx, running_threads);
    }
}

int main() {
    double a = 0.0, b = 1.0;
    double eps = 1e-6;
    double whole = simpson(a, b);

    mutex mtx;
    int running_threads = 0;

    double result = adaptive_simpson(a, b, eps, whole, mtx, running_threads);

    cout << "The area of the quarter circle with radius 1 is: " << result << endl;
    cout << "Number of running threads: " << running_threads << endl;

    return 0;
}
