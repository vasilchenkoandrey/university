#include <iostream>
#include <future>
#include <cmath>
#include <vector>

using namespace std;

double f(double x) {
    return sqrt(1 - x * x);
}

double simpson_integrate(double a, double b, double eps) {
    double h = (b - a) / 2.0;
    double fa = f(a);
    double fb = f(b);
    double fm = f((a + b) / 2.0);

    double integral = h / 3.0 * (fa + 4.0 * fm + fb);

    return integral;
}

double integral(double eps, int num_threads) {
    double a = 0.0;
    double b = 1.0;
    double h = (b - a) / num_threads;

    vector<future<double>> futures;

    for (int i = 0; i < num_threads; ++i) {
        double left = a + i * h;
        double right = left + h;

        futures.push_back(async(launch::async, simpson_integrate, left, right, eps));
    }

    double sum = 0.0;
    for (int i = 0; i < num_threads; ++i) {
        sum += futures[i].get();
    }

    return sum;
}

int main() {
    double eps = 1e-6;
    int num_threads = 4;

    double res = integral(eps, num_threads);
    cout << "Integral: " << res << endl;

    return 0;
}
