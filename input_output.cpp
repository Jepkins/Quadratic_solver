#include <stdio.h>
#include <math.h>
#include "definitions.h"
#include "input_output.h"

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
    int a;
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
	 case INPUT_ERROR: printf("Input Error!\n");
	 	  return 1;
    case UNDEFINED: default: printf("Error, n_roots = %d\n", solt.n_roots);
        return 1;
    }
    return 0;
}
