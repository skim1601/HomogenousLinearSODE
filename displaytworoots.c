#include <stdio.h>
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
