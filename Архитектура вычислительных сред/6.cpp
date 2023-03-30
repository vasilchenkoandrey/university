#include <iostream>
#include <thread>
#include <vector>
#include <cmath>
#include <mutex>

using namespace std;

double f(double x) {
    return sqrt(1 - x * x);
}

double simpson(double a, double b) {
    double c = (a + b) / 2.0;
    return (f(a) + 4 * f(c) + f(b)) * (b - a) / 6.0;
}

double adaptive_simpson(double a, double b, double eps, double whole, int& threads_count, mutex& mtx) {
    double c = (a + b) / 2.0;
    double left = simpson(a, c);
    double right = simpson(c, b);
    double result = left + right;

    if (fabs(result - whole) <= 15 * eps) {
        return result + (result - whole) / 15.0;
    } else {
        double result_left = 0.0, result_right = 0.0;
        thread thread_left([&](){
            mtx.lock();
            threads_count++;
            mtx.unlock();
            result_left = adaptive_simpson(a, c, eps / 2.0, left, threads_count, mtx);
        });
        thread thread_right([&](){
            mtx.lock();
            threads_count++;
            mtx.unlock();
            result_right = adaptive_simpson(c, b, eps / 2.0, right, threads_count, mtx);
        });
        thread_left.join();
        thread_right.join();
        return result_left + result_right;
    }
}

int main() {
    double a = 0.0, b = 0.80;
    double eps = 1e-6;
    double whole = simpson(a, b);

    int threads_count = 0;
    mutex mtx;

    double result = adaptive_simpson(a, b, eps, whole, threads_count, mtx);

    cout << "The area of the quarter circle with radius 1 is: " << result << endl;
    cout << "Threads count: " << threads_count << endl;

    return 0;
}
