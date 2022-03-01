#include <stdio.h>
#include "secorderode.c"

void tester(void){
    double a, b, c;

    printf("Solving this DE: ay'' + by' + cy = 0\n");
    printf("Enter your a value: ");
    scanf("%lf", &a);

    printf("Enter your b value: ");
    scanf("%lf", &b);

    printf("Enter your c value: ");
    scanf("%lf", &c);

    homogenousDifferentialSolver(a, b, c);
}

int main(void){
    tester();
}