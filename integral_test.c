#include "integral.h"
#include <assert.h>
#include <math.h>

double test_func_sq(double x) { return x * x; }

double test_func_lin(double x) { return 2.0 * x; }

double test_func_const(double x) {
  (void)x;
  return 5.0;
}

void test_integral_square() {
  double a = 0.0;
  double b = 1.0;
  int n = 1000;
  double expected = 1.0 / 3.0;
  double eps = 1e-4;

  double res = calculate_integral(test_func_sq, a, b, n);

  assert(fabs(res - expected) < eps);
}

void test_integral_linear() {
  double a = 0.0;
  double b = 2.0;
  int n = 1000;
  double expected = 4.0;
  double eps = 1e-4;

  double res = calculate_integral(test_func_lin, a, b, n);

  assert(fabs(res - expected) < eps);
}

void test_integral_constant() {
  double a = 0.0;
  double b = 10.0;
  int n = 1000;
  double expected = 50.0;
  double eps = 1e-4;

  double res = calculate_integral(test_func_const, a, b, n);

  assert(fabs(res - expected) < eps);
}

int main(void) {
  test_integral_square();
  test_integral_linear();
  test_integral_constant();

  return 0;
}