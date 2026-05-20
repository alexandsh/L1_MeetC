#include "quadratic.h"
#include <math.h>

static const double EPS = 1e-7;

static inline int sgn(double a) { return a >= 0 ? 1 : -1; }

int solve_quadratic(double a, double b, double c, double *x1, double *x2) {
  if (fabs(a) < EPS)
    return -1;

  double D = b * b - 4 * a * c;

  if (D < -EPS)
    return 0;

  if (fabs(D) <= EPS) {
    *x1 = -b / (2 * a);
    return 1;
  }

  double sqrtD = sqrt(D);
  double q = -(b + sgn(b) * sqrtD) / 2;

  *x1 = q / a;
  *x2 = c / q;

  if (*x1 > *x2) {
    double tmp = *x1;
    *x1 = *x2;
    *x2 = tmp;
  }

  return 2;
}
