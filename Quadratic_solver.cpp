/**
\file
\brief Program solving up to 2nd degree polynominal equations

This program asks user to enter 3 coefficients of a quadratic equation and outputs all of its roots
*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include "definitions.h"
#include "double_arithmetics.h"
#include "define_equation_and_solve.h"
#include "Tester.h"

/// Asks user to input coefficients of a quadratic equation
/**
Notice: Input is protected from a non-number values
\param double[out] <b>a, b, c</b>\n
Coefficients for reading
*/
void Input_Coefficients(Coefficients *coeff);

/// Outputs the solutions of a quadratic equation
/**
\param N_OF_SOLUTIONS[in] \b roots_number
Number of solutions
\param double[in] <b>x1, x2</b>
Solutions for output
\return \b 0 in case of successful printing
\return \b 1 in case of invalid roots_number value
*/
bool Output_Roots(Solution solt);

/// Clears input buffer
void Clear_Buffer();

/// Initializes input, proccessing and output
/*
-r to run main program
-t to run unit tester
*/

int main(int argc, char *argv[])
{
    int c;
    bool solver_run = 0, tester_run = 0;
    while (--argc > 0 && (*++argv)[0] == '-')

        while (c = *++argv[0])

            switch (c)
            {
            case 'r':
                solver_run = 1;
                break;
            case 't' :
                tester_run = 1;
                break;
            default :
                printf( "Incorrect parameter: %d\n", c);
                argc = -1;
                break;
            }

    if (argc != 0)
    {
    printf("Use: -r -t -rt\n");
    return 1;
    }

    if (tester_run)
    {
    Run_All_Tests();
    }

    if (solver_run)
    {
    Coefficients coeff = {0, 0, 0};
    Input_Coefficients(&coeff);

    Solution solt = {0, 0, UNDEFINED};
    Quad_Define_and_Solve(coeff, &solt);

    Output_Roots(solt);
    }

    return 0;
}

void Input_Coefficients(Coefficients *coeff)
{
    double a = 0, b = 0, c = 0;
    printf("Enter a, b, c\n");
    while ((scanf("%lg %lg %lg", &a, &b, &c) != 3) || !(isfinite(a) && isfinite(b) && isfinite(c))) {
        Clear_Buffer();
        printf("Incorrect input\n\n");
        printf("Enter a, b, c\n");
    }
    coeff->a = a;
    coeff->b = b;
    coeff->c = c;
}

void Clear_Buffer()
{
    char a;
    do {
        a = getchar();
    } while (a != EOF && a != '\n');
}

bool Output_Roots(Solution solt)
{
    switch (solt.n_roots)
    {
    case NO_SOLUTIONS: printf("No Solutions\n");
        break;
    case ONE_SOLUTION: printf("x1 = %lg\n", solt.x1);
        break;
    case TWO_SOLUTIONS: printf("x1 = %lg, x2 = %lg\n", solt.x1, solt.x2);
        break;
    case INF_SOLUTIONS: printf("Any Number\n");
        break;
    default: printf("Error, n_roots = %d\n", solt.n_roots);
        return 1;
    }
    return 0;
}

















