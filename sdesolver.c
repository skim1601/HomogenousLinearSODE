#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// Display the solution of homoegenous and linear second order DE with two real characteristic equation solutions
void displayTwoRoots (double r1, double r2, double c, double d, bool constantFound){
    printf("Possible solution: y(t) = ");
    
    if (constantFound){
        printf("%lf", c);
    } else {
        printf("C");
    }

    if (r1 != 0){
        printf("e^(%lft) ", r1);
    }

    if (constantFound){
        printf(" + (%lf)", d);
    } else {
        printf(" + D");
    }

    if (r2 != 0){
        printf("e^(%lft)", r2);
    }

    printf("\n\n");
    return;
}

// Algorithm:
// y = c + d
// yPrime = c * r1 + d * r2
// d = y - c
// yPrime = c * r1 + (y - c) * r2 
// c = (yPrime - y * r2) / (r1 - r2)
void twoRootsInitial (double* constants, double r1, double r2, double y, double yPrime){
    *constants = (yPrime - y * r2) / (r1 - r2);
    *(constants + 1) = y - *constants;
    return;
}

void twoRoots(double a, double b, double c){
    double r1 = (-1 * b + sqrt(b * b - 4 * a * c)) / (2 * a);
    double r2 = (-1 * b - sqrt(b * b - 4 * a * c)) / (2 * a);
    double initialY, initialYPrime;
    double constants [2];

    displayTwoRoots(r1, r2, 0, 0, false);

    printf("Trying initial values\n");
    printf("y(0): ");
    scanf("%lf", &initialY);
    printf("y'(0): ");
    scanf("%lf", &initialYPrime);

    twoRootsInitial(constants, r1, r2, initialY, initialYPrime);

    printf("\nCalculated initial values\n");
    displayTwoRoots(r1, r2, constants[0], constants[1], true);
    return;
}

// Display the solution of homoegenous and linear second order DE with one real characteristic equation solution
void displayOneRoot (double r, double c, bool constantFound){
    printf("Possible solution: y(t) = ");

    if (constantFound){
        printf("%lf", c);
    } else {
        printf("C");
    }

    if (r != 0){
        printf(" * e^(%lft)", r);
    }

    printf("\n\n");
    return;
}

void oneRoot(double a, double b){
    double r = (-1 * b) / (2 * a);
    double initialY;

    displayOneRoot(r, 0, false);
        
    printf("Trying initial value\n");
    printf("y(0) = ");
    scanf("%lf", &initialY);

    printf("\nCalculated initial value\n");
    displayOneRoot(r, initialY, true);
}

// Display the solution of homoegenous and linear second order DE with no real characteristic equation solution
// y1 = c * e ^ (k * t) * cos (a * t)
// y2 = d * e ^ (k * t) * sin (a * t)
void displayNoRoot (double k, double a, double c, double d, bool constantFound){
    printf("Possible solution: y(t) = ");
    
    if (constantFound){
        printf("%lf", c);
    } else {
        printf("C");
    }

    if (k != 0){
        printf("e^(%lft) * cos(%lft)", k, a);
    }

    if (constantFound){
        printf(" + (%lf)", d);
    } else {
        printf(" + D");
    }

    if (k != 0){
        printf("e^(%lft) * sin(%lft)", k, a);
    }

    printf("\n\n");
    return;
}

// Algorithm
// y = c
// yPrime = c * k + d * a 
// d = (yPrime - c * k) / a
void noRootInitial (double* constants, double k, double a, double y, double yPrime){
    *constants = y;
    *(constants + 1) = (yPrime - *constants * k) / a;
    return;
}

void noRoot(double a, double b, double c){
    double k = (-1 * b) / (2 * a);
    double alpha = sqrt((b * b - 4 * a * c) / -1) / (2 * a);
    double initialY, initialYPrime;
    double constants [2];

    displayNoRoot(k, alpha, 0, 0, false);

    printf("Trying initial values\n");
    printf("y(0): ");
    scanf("%lf", &initialY);
    printf("y'(0): ");
    scanf("%lf", &initialYPrime);
    noRootInitial(constants, k, alpha, initialY, initialYPrime);

    printf("\nCalculated initial values\n");
    displayNoRoot(k, alpha, constants[0], constants[1], true);
}


// A function that solves homogenous second order differential equation
// ay'' + by' + cy = 0
void secondaryDifferentialSolver(double a, double b, double c){
    printf("Your equation: (%lf)y'' + (%lf)y' + (%lf)y = 0\n", a, b, c);

    if (b * b - 4 * a * c > 0){
        twoRoots(a, b, c);

    } else if (b * b - 4 * a * c == 0){
        oneRoot(a, b);

    } else {
        noRoot(a, b, c);
    }

    return;
}