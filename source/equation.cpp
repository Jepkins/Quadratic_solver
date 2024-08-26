#include <math.h>
#include "..\lib\definitions.h"
#include "..\lib\double_arithmetics.h"
#include "..\lib\equation.h"


void solve_full_quad(double a, double b, double c, Solution *solt)
{
    if (!(isfinite(a) && isfinite(b) && isfinite(c)))
    {
        solt->n_roots = INPUT_ERROR;
        return;
    }

    if (is_zero(a))
    {
        solve_linear(b, c, solt);
        return;
    }

    double d = b*b - 4*a*c;

    if (is_zero(d)) {
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

void solve_linear(double b, double c, Solution *solt)
{
    if (is_zero(b))
    {
        solve_constant(c, solt);
        return;
    }

    solt->x1 = -c / b;
    solt->n_roots = ONE_SOLUTION;
}

void solve_constant(double c, Solution *solt)
{
    solt->n_roots = ((is_zero(c))? INF_SOLUTIONS : NO_SOLUTIONS);
}
