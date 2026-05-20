#include "quadratic.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>

void test_zero_a() {
  double x1, x2;
  int n = solve_quadratic(0, 1, 1, &x1, &x2);
  assert(n == -1);
}

void test_positive_discriminant() {
  double x1, x2;
  int n = solve_quadratic(1, 0, -1, &x1, &x2);
  assert(n == 2);
  assert(fabs(x1 - (-1)) < 1e-9);
  assert(fabs(x2 - 1) < 1e-9);
}

void test_zero_discriminant() {
  double x1, x2;
  int n = solve_quadratic(1, 0, 0, &x1, &x2);
  assert(n == 1);
  assert(fabs(x1) < 1e-9);
}

void test_negative_discriminant() {
  double x1, x2;
  int n = solve_quadratic(1, 0, 1, &x1, &x2);
  assert(n == 0);
}

void test_small_roots() {
  double x1, x2;
  int n = solve_quadratic(1, 0, -1e-7, &x1, &x2);
  assert(n == 2);
  assert(fabs(x1 - (-3e-4)) < 1e-4);
  assert(fabs(x2 - 3e-4) < 1e-4);
}

void test_large_b() {
  double x1, x2;
  int n = solve_quadratic(1, -1e+10, -1, &x1, &x2);
  assert(n == 2);
  assert(fabs(x1 - (-1e-10)) < 1e-11);
  assert(fabs(x2 - 1e+10) < 1e-11);
}

void test_nearly_zero_discriminant() {
  double x1, x2;
  int n = solve_quadratic(1, 0, -1e-8, &x1, &x2);
  assert(n == 1);
  assert(fabs(x1) < 1e-7);
}

int main() {
  test_zero_a();
  test_positive_discriminant();
  test_zero_discriminant();
  test_negative_discriminant();
  test_small_roots();
  test_large_b();
  test_nearly_zero_discriminant();
  printf("Ура, Победа, все тесты пройдены!!!\n");
  return 0;
}
