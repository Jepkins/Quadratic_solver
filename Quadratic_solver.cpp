/**
\file
\brief Program solving up to 2nd degree polynominal equations

This program asks user to enter 3 coefficients of a quadratic equation and outputs all of its roots
*/

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "flagging.h"
#include "double_arithmetics.h"
#include "define_equation_and_solve.h"

/// Asks user to input coefficients of a quadratic equation
/**
Notice: Input is protected from a non-number values
\param double[out] <b>a, b, c</b>\n
Coefficients for reading
*/
void Input_Coefficients(double* a, double* b, double* c);

/// Outputs the solutions of a quadratic equation
/**
\param N_OF_SOLUTIONS[in] \b roots_number
Number of solutions
\param double[in] <b>x1, x2</b>
Solutions for output
\return \b 0 in case of successful printing
\return \b 1 in case of invalid roots_number value
*/
bool Output_Roots(N_OF_SOLUTIONS roots_number, double x1, double x2);

/// Clears input buffer
void Clear_Buffer();

/// Initializes input, proccessing and output
int main()
{
    double a=0, b=0, c=0;
    Input_Coefficients(&a, &b, &c);

    double x1=0, x2=0;
    enum N_OF_SOLUTIONS roots_number = Quad_Define_and_Solve(a, b, c, &x1, &x2);

    return Output_Roots(roots_number, x1, x2);
}

void Input_Coefficients(double* a, double* b, double* c)
{
    printf("Enter a, b, c\n");
    while (scanf("%lg %lg %lg", a, b, c) != 3) {
        Clear_Buffer();
        printf("Incorrect input\n");
        printf("Enter a, b, c\n");
    }
}

void Clear_Buffer()
{
    char a;
    do {
        a = getchar();
    } while (a != EOF && a != '\n');
}

bool Output_Roots(N_OF_SOLUTIONS roots_number, double x1, double x2)
{
    switch (roots_number)
    {
    case NO_SOLUTIONS: printf("No Solutions\n");
        break;
    case ONE_SOLUTION: printf("x1 = %lg\n", x1);
        break;
    case TWO_SOLUTIONS: printf("x1 = %lg, x2 = %lg\n", x1, x2);
        break;
    case INF_SOLUTIONS: printf("Any Number\n");
        break;
    default: printf("Error, roots_number = %d\n", roots_number);
        return 1;
    }
    return 0;
}

















