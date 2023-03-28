#include <iostream>
#include <cmath>
#include <thread>

using namespace std;

double f(double x) {
    return sqrt(1 - x * x);
}

double simpson(double a, double b) {
    double c = (a + b) / 2.0;
    return (f(a) + 4 * f(c) + f(b)) * (b - a) / 6.0;
}

double adaptive_simpson(double a, double b, double eps, double whole) {
    double c = (a + b) / 2.0;
    double left, right;
    thread left_thread, right_thread;

    left_thread = thread([&]() { left = simpson(a, c); });
    right_thread = thread([&]() { right = simpson(c, b); });

    left_thread.join();
    right_thread.join();

    double result = left + right;

    if (fabs(result - whole) <= 15 * eps) {
        return result + (result - whole) / 15.0;
    } else {
        return adaptive_simpson(a, c, eps / 2.0, left) + adaptive_simpson(c, b, eps / 2.0, right);
    }
}

int main() {
    double a = 0.0, b = 1.0;
    double eps = 1e-6;
    double whole = simpson(a, b);

    double result = adaptive_simpson(a, b, eps, whole);

    cout << "The area of the quarter circle with radius 1 is: " << result << endl;

    return 0;
}
