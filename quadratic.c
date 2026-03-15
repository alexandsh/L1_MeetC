#include "quadratic.h"
#include <math.h>

int solve_quadratic(double a, double b, double c, double *x1, double *x2) {
  if (a == 0)
    return -1;

  double D = b * b - 4 * a * c;
  double eps = 1e-7;

  if (D < -eps)
    return 0;

  if (fabs(D) <= eps) {
    *x1 = -b / (2 * a);
    return 1;
  }

  double sqrtD = sqrt(D);
  double q;
  if (b >= 0)
    q = -(b + sqrtD) / 2;
  else
    q = -(b - sqrtD) / 2;

  *x1 = q / a;
  *x2 = c / q;

  if (*x1 > *x2) {
    double tmp = *x1;
    *x1 = *x2;
    *x2 = tmp;
  }

  return 2;
}
