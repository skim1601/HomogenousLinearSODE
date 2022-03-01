#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "displaytworoots.c"
#include "displayoneroot.c"
#include "displaynoroot.c"
#include "twoinitialvaluessolver.c"
#include "imaginaryinitialvaluessolver.c"

// A tool to solve homogenous second order differential equation
// ay'' + by' + cy = 0
void homogenousDifferentialSolver(double a, double b, double c){
    printf("Your equation: (%lf)y'' + (%lf)y' + (%lf)y = 0\n", a, b, c);

    if (b * b - 4 * a * c > 0){
        double r1 = (-1 * b + sqrt(b * b - 4 * a * c)) / (2 * a);
        double r2 = (-1 * b - sqrt(b * b - 4 * a * c)) / (2 * a);

        displayTwoRoots(r1, r2, 0, 0, false);

        double initialY, initialYPrime;
        double constants [2];

        printf("Trying initial values\n");
        printf("y(0): ");
        scanf("%lf", &initialY);
        printf("y'(0): ");
        scanf("%lf", &initialYPrime);

        twoInitialValuesSolver(constants, r1, r2, initialY, initialYPrime);

        printf("\nCalculated initial values\n");
        displayTwoRoots(r1, r2, constants[0], constants[1], true);

    } else if (b * b - 4 * a * c == 0){
        double r = (-1 * b) / (2 * a);

        displayOneRoot(r, 0, false);
        
        double initialY;
        printf("Trying initial value\n");
        printf("y(0) = ");
        scanf("%lf", &initialY);

        printf("\nCalculated initial value\n");
        displayOneRoot(r, initialY, true);
        
    } else {
        double k = (-1 * b) / (2 * a);
        double alpha = sqrt((b * b - 4 * a * c) / -1) / (2 * a);

        displayNoRoot(k, alpha, 0, 0, false);

        double initialY, initialYPrime;
        double constants [2];

        printf("Trying initial values\n");
        printf("y(0): ");
        scanf("%lf", &initialY);
        printf("y'(0): ");
        scanf("%lf", &initialYPrime);

        
        imaginaryInitialValuesSolver(constants, k, alpha, initialY, initialYPrime);

        printf("\nCalculated initial values\n");
        displayNoRoot(k, alpha, constants[0], constants[1], true);
    }

    return;
}
