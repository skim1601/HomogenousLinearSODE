#include <stdio.h>
#include <stdbool.h>

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

    printf("\n");
    return;
}