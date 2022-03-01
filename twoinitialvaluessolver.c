#include <stdio.h>

// Algorithm:
// y = c + d
// yPrime = c * r1 + d * r2
// d = y - c
// yPrime = c * r1 + (y - c) * r2 
// c = (yPrime - y * r2) / (r1 - r2)
void twoInitialValuesSolver (double* constants, double r1, double r2, double y, double yPrime){
    *constants = (yPrime - y * r2) / (r1 - r2);
    *(constants + 1) = y - *constants;
    return;
}
