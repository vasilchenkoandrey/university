#include <iostream>
#include <future>
#include <cmath>
#include <vector>
#include <mutex>

using namespace std;

double f(double x) {
    return sqrt(1 - x * x);
}

double simpson_integrate(double a, double b, double eps, mutex& mtx, int& num_threads, int& max_threads) {
    double h = (b - a) / 2.0;
    double fa = f(a);
    double fb = f(b);
    double fm = f((a + b) / 2.0);

    double integral = h / 3.0 * (fa + 4.0 * fm + fb);

    mtx.lock();
    num_threads--;
    if (num_threads > max_threads) {
        max_threads = num_threads;
    }
    mtx.unlock();

    return integral;
}

double integral(double eps, int num_threads, int& max_threads) {
    double a = 0.0;
    double b = 1.0;
    double h = (b - a) / num_threads;
    mutex mtx;

    vector<future<double>> futures;
    int working_threads = 0;

    for (int i = 0; i < num_threads; ++i) {
        double left = a + i * h;
        double right = left + h;

        futures.push_back(async(launch::async, simpson_integrate, left, right, eps, ref(mtx), ref(working_threads), ref(max_threads)));

        mtx.lock();
        working_threads++;
        if (working_threads > max_threads) {
            max_threads = working_threads;
        }
        mtx.unlock();
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
    int max_threads = num_threads;

    double res = integral(eps, num_threads, max_threads);
    cout << "Integral: " << res << endl;
    cout << "Limit thread: " << num_threads << endl;
    cout << "Max threads: " << max_threads << endl;

    return 0;
}
