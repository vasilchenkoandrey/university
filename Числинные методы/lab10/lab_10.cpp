#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;

double func(double x)
{
  return cos(x);
}

double func1(double x)
{
  return -sin(x);
}

double dihotomiya(double x0, double x1, double eps)
{
  double left = x0, right = x1, x, fl, fr, f;
  int iter = 0;
  do {
    x = (left + right) / 2;
    f = func(x);
    if (f > 0) right = x;
    else left = x;
    iter++;
  } while (fabs(f) > eps && iter<20000);
  return x;
}

double newton(double x, double eps)
{
  double f, df; int iter = 0;
  do {
    x = x - func(x) / func1(x);
    iter++;
  } while (fabs(f) > eps && iter<20000);
  return x;
}

int main() 
{
  cout << dihotomiya(0, M_PI/2, 0.000001);
  cout << newton(0, 10.0, 0.000001);
  cin.get(); return 0;
}