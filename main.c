#include <stdio.h>
#include <math.h>    
#include "integral.h" 

double test_function(double x) {
    return x * x;
}

int main() {
    double a = 0.0;
    double b = 1.0;
    int n = 1000; 

    double expected_value = 1.0/3.0;
    double result = calculate_integral(test_function, a, b, n);

    printf("%.10f\n",result);
    printf("%.10f\n",expected_value);

    double epsilon = 1e-6; 
    if (fabs(result - expected_value) < epsilon) {
        printf("НОРМ\n");
    } else {
        printf("НЕ НОРМ\n");
    }
    return 0;
}