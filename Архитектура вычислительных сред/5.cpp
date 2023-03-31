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

void adaptive_simpson(double a, double b, double eps, double whole, double& result) {
    double c = (a + b) / 2.0;

    double left, right;
    thread left_thread([=, &left]() { left = simpson(a, c); });
    thread right_thread([=, &right]() { right = simpson(c, b); });

    left_thread.join();
    right_thread.join();

    result = left + right;

    if (fabs(result - whole) <= 15 * eps) {
        result += (result - whole) / 15.0;
    } else {
        double result1, result2;
        thread thread1([=, &result1]() { adaptive_simpson(a, c, eps / 2.0, left, result1); });
        thread thread2([=, &result2]() { adaptive_simpson(c, b, eps / 2.0, right, result2); });

        thread1.join();
        thread2.join();

        result = result1 + result2;
    }
}

int main() {
    double a = 0.0, b = 1.0;
    double eps = 1e-6;
    double whole = simpson(a, b);
    double result = 0.0;

    adaptive_simpson(a, b, eps, whole, result);

    cout << "The area of the quarter circle with radius 1 is: " << result << endl;

    return 0;
}
