#include <math.h>
#include "definitions.h"
#include "double_arithmetics.h"
#include "define_equation_and_solve.h"


void Quad_Define_and_Solve(Coefficients coeff, Solution *solt)
{
    if (!(isfinite(coeff.a) && isfinite(coeff.b) && isfinite(coeff.c)))
    {
        solt->n_roots = INPUT_ERROR;
        return;
    }

    if (!Is_Zero(coeff.a))
    {
        Solve_Full_Quad(coeff.a, coeff.b, coeff.c, solt);
        return;
    }

    if (!Is_Zero(coeff.b))
    {
        Solve_Linear(coeff.b, coeff.c, solt);
        return;
    }

    Solve_Constant(coeff.c, solt);
}

void Solve_Full_Quad(double a, double b, double c, Solution *solt)
{
    double d = b*b - 4*a*c;

    if (Is_Zero(d)) {
        solt->x1 = (-b)/(2*a);
        solt->n_roots = ONE_SOLUTION;
        return;
    }

    if (d > 0)  {
        double sqrt_d = sqrt(d);
        solt->x1 = (-b-sqrt_d)/(2*a);
        solt->x2 = (-b+sqrt_d)/(2*a);
        solt->n_roots = TWO_SOLUTIONS;
        return;
    }

    solt->n_roots = NO_SOLUTIONS;
}

void Solve_Linear(double b, double c, Solution *solt)
{
    solt->x1 = -c/b;
    solt->n_roots = ONE_SOLUTION;
}

void Solve_Constant(double c, Solution *solt)
{
    solt->n_roots = ((Is_Zero(c))? INF_SOLUTIONS : NO_SOLUTIONS);
}
