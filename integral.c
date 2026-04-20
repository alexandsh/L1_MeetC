#include "integral.h"

double calculate_integral(double (*func)(double), double a, double b, int n) {
  if (n <= 0)
    return 0.0;

  double h = (b - a) / n;

  double sum = (func(a) + func(b)) / 2.0;

  for (int i = 1; i < n; i++) {
    double x_i = a + i * h;
    sum += func(x_i);
  }

  return sum * h;
}