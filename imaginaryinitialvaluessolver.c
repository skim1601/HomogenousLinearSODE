#include <stdio.h>

// Algorithm
// y = c
// yPrime = c * k + d * a 
// d = (yPrime - c * k) / a
void imaginaryInitialValuesSolver (double *constants, double k, double a, double y, double yPrime){
    *constants = y;
    *(constants + 1) = (yPrime - *constants * k) / a;
    return;
}
