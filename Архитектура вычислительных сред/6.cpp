#include <iostream>
#include <thread>
#include <vector>
#include <cmath>
#include <atomic>

using namespace std;

double f(double x) {
    return sqrt(1 - x * x);
}

double simpson(double a, double b) {
    double c = (a + b) / 2.0;
    return (f(a) + 4 * f(c) + f(b)) * (b - a) / 6.0;
}

double adaptive_simpson(double a, double b, double eps, double whole, atomic<int>& threads_count) {
    double c = (a + b) / 2.0;
    double left = simpson(a, c);
    double right = simpson(c, b);
    double result = left + right;

    if (fabs(result - whole) <= 15 * eps) {
        return result + (result - whole) / 15.0;
    } else {
        if (threads_count < 2) { // Ограничиваем максимальное количество потоков
            double result_left = 0.0, result_right = 0.0;
            threads_count++;
            thread thread_left([&](){
                result_left = adaptive_simpson(a, c, eps / 2.0, left, threads_count);
            });
            threads_count++;
            thread thread_right([&](){
                result_right = adaptive_simpson(c, b, eps / 2.0, right, threads_count);
            });
            thread_left.join();
            thread_right.join();
            return result_left + result_right;
        } else { // Переходим к рекурсивному вычислению, если количество потоков превысило максимальное
            double result_left = adaptive_simpson(a, c, eps / 2.0, left, threads_count);
            double result_right = adaptive_simpson(c, b, eps / 2.0, right, threads_count);
            return result_left + result_right;
        }
    }
}

int main() {
    double a = 0.0, b = 1;
    double eps = 1e-6;
    double whole = simpson(a, b);

    atomic<int> threads_count(0);

    double result = adaptive_simpson(a, b, eps, whole, threads_count);

    cout << "The area of the quarter circle with radius 1 is: " << result << endl;
    

    return 0;
}
