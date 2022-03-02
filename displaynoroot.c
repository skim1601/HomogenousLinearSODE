#include <stdio.h>
#include <stdbool.h>

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
        printf("e^(%lft) * cos(%lft)", k, a);
    }

    printf("\n\n");
    return;
}
