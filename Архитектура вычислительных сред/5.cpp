#include <iostream>
#include <thread>
#include <vector>
#include <cmath>

using namespace std;

double f(double x) {
    return sqrt(1 - x * x);
}

double integrate(double a, double b, double eps) {
    double h = b - a;
    double c = (a + b) / 2.0;
    double fa = f(a);
    double fb = f(b);
    double fc = f(c);
    double S = h / 6.0 * (fa + 4.0 * fc + fb);
    return S;
}

void integrate_thread(double a, double b, double eps, double& result) {
    result = integrate(a, b, eps);
}

double adaptive_integrate(double a, double b, double eps, int threads) {
    double h = b - a;
    double c = (a + b) / 2.0;
    double fa = f(a);
    double fb = f(b);
    double fc = f(c);
    double S = h / 6.0 * (fa + 4.0 * fc + fb);
    double S1 = h / 12.0 * (fa + 4.0 * f((a + c) / 2.0) + 2.0 * fc + 4.0 * f((b + c) / 2.0) + fb);
    double err = fabs(S1 - S) / 15.0;
    if (err < eps) {
        return S1;
    }
    else {
        double S_left, S_right;
        vector<double> results(2, 0.0);
        vector<thread> thread_pool;
        thread_pool.emplace_back([&]() { results[0] = adaptive_integrate(a, c, eps / 2.0, threads / 2); });
        thread_pool.emplace_back([&]() { results[1] = adaptive_integrate(c, b, eps / 2.0, threads / 2); });
        for (auto& thread : thread_pool) {
            thread.join();
        }
        return results[0] + results[1];
    }
}

int main() {
    const double R = 1.0;
    double a = 0.0, b = R;
    double eps = 1e-6;
    int threads = 4;
    double result = adaptive_integrate(a, b, eps, threads);
    double area = result * 4.0;
    cout << "Area of quarter circle with radius " << R << " = " << area << endl;
    return 0;
}