#include <stdio.h>
#include <math.h>
#include <stdbool.h>

typedef struct twoRoot{
    double root1, root2;
    double y, yPrime;
    double constant1, constant2;
} TwoRoot;

typedef struct oneRoot{
    double root;
    double y;
    double constant;
} OneRoot;

typedef struct noRoot{
    double alpha, beta; // Complex root: alpha +- beta * i
    double y, yPrime;
    double constant1, constant2;
} NoRoot;

// Display the solution of homoegenous and linear second order DE with two real characteristic equation solutions
void displayTwoRoots (TwoRoot* eq, bool constantFound){
  printf("Possible solution: y(t) = ");
  
  if (constantFound){
    printf("%lf", eq -> constant1);
  } else {
    printf("C");
  }

  if (eq -> root1 != 0){
    printf(" * e^(%lft)", eq -> root1);
  }

  if (constantFound){
    printf(" + (%lf)", eq -> constant2);
  } else {
    printf(" + D");
  }

  if (eq -> root2 != 0){
    printf(" * e^(%lft)", eq -> root2);
  }

  printf("\n\n");
  return;
}

// Algorithm:
// Given initial value: (t, y, y') = (0, y, y')
// y = constant1 + constant2
// yPrime = constant1 * root1 + constant2 * root2
// constant2 = y - constant1
// yPrime = constant1 * root1 + (y - constant2) * root2 
// constant1 = (yPrime - y * root2) / (root1 - root2)
void twoRootsInitial (TwoRoot* eq){
  eq -> constant1 = (eq -> yPrime - eq -> y * eq -> root2) / (eq -> root1 - eq -> root2);
  eq -> constant2 = eq -> y - eq -> constant1;
  return;
}

// a * r^2 + b * r + c = 0
// b^2 - 4 * a * c > 0
void twoRoots(double a, double b, double c){
  TwoRoot equation = {0, 0, 0, 0, 0, 0}; 
  TwoRoot* eq = &equation;

  eq -> root1 = (-1 * b + sqrt(b * b - 4 * a * c)) / (2 * a);
  eq -> root2 = (-1 * b - sqrt(b * b - 4 * a * c)) / (2 * a);
  displayTwoRoots(eq, false);

  printf("Trying initial values\n");
  printf("y(0): ");
  scanf("%lf", &(eq -> y));
  printf("y'(0): ");
  scanf("%lf", &(eq -> yPrime));

  twoRootsInitial(eq);

  printf("\nCalculated initial values\n");
  displayTwoRoots(eq, true);
  return;
}

// Display the solution of homoegenous and linear second order DE with one real characteristic equation solution
void displayOneRoot (OneRoot* eq, bool constantFound){
  printf("Possible solution: y(t) = ");

  if (constantFound){
      printf("%lf", eq -> constant);
  } else {
      printf("C");
  }

  if (eq -> root != 0){
      printf(" * e^(%lft)", eq -> root);
  }

  if (constantFound){
      printf(" + C");
  } else {
      printf(" + D");
  }

  if (eq -> root != 0){
      printf(" * t * e^(%lft)", eq -> root);
  }

  printf("\n\n");
  return;
}


// Algorithm:
// Given initial value: (t, y, y') = (0, y, y')
// y = constant1
// constant2 cannot be found as t (= 0) is multiplied to the term involving constant2
void oneRootInitial (OneRoot* eq){
  eq -> constant = eq -> y;
  return;
}

// ar^2 + br + c = 0
// b^2 - 4ac = 0
void oneRoot(double a, double b){
  OneRoot equation = {0, 0, 0}; 
  OneRoot* eq = &equation;

  eq -> root = (-1 * b) / (2 * a);

  displayOneRoot(eq, false);
      
  printf("Trying initial value\n");
  printf("y(0) = ");
  scanf("%lf", &(eq -> y));

  oneRootInitial(eq);

  printf("\nCalculated initial value\n");
  displayOneRoot(eq, true);
}

// Display the solution of homoegenous and linear second order DE with no real characteristic equation solution
// y1 = constant1 * e ^ (alpha * t) * cos (beta * t)
// y2 = constant2 * e ^ (alpha * t) * sin (beta * t)
void displayNoRoot (NoRoot* eq, bool constantFound){
  printf("Possible solution: y(t) = ");
  
  if (constantFound){
    printf("%lf", eq -> constant1);
  } else {
    printf("C");
  }

  if (eq -> alpha != 0){
    printf(" * e^(%lft)", eq -> alpha);
  }

  printf(" * cos(%lft)", eq -> beta);
  

  if (constantFound){
    printf(" + (%lf)", eq -> constant2);
  } else {
    printf(" + D");
  }

  if (eq -> alpha != 0){
    printf(" * e^(%lft)", eq -> alpha);
  }

  printf(" * sin(%lft)\n\n", eq -> beta);
  return;
}

// Algorithm
// Given initial value: (t, y, y') = (0, y, y')
// y = constant1
// Given initial value: (t, y, y') = (t, y, y')
// yPrime = constant1 * alpha + constant2 * beta
// constant2 = (yPrime - constant1 * alpha) / beta
void noRootInitial (NoRoot* eq){
  eq -> constant1 = eq -> y;
  eq -> constant2 = (eq -> yPrime - eq -> constant1 * eq -> alpha) / eq -> beta;
  return;
}

// a * r^2 + b * r + c = 0
// b^2 - 4 * a * c < 0
void noRoot(double a, double b, double c){
  NoRoot equation = {0, 0, 0, 0, 0, 0}; 
  NoRoot* eq = &equation;
  
  eq -> alpha = (-1 * b) / (2 * a);
  eq -> beta = sqrt((b * b - 4 * a * c) / -1) / (2 * a);
  displayNoRoot(eq, false);

  printf("Trying initial values\n");
  printf("y(0): ");
  scanf("%lf", &(eq -> y));
  printf("y'(0): ");
  scanf("%lf", &(eq -> yPrime));
  noRootInitial(eq);

  printf("\nCalculated initial values\n");
  displayNoRoot(eq, true);
  return;
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
