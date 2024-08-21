/**
\file
\brief Provides functions for solving up to 2nd degree polynominal equations
*/

/// Defines the type of equation and passes on to the solving functions
/**
\param double[in] <b>a, b, c</b>\n
Coefficients of a quadratic equation

\param double[out] <b>x1, x2</b>\n
Solutions of the equation. If number of roots is less than 2 all additional solutions remain unmodified

\return <b>enum N_OF_SOLUTIONS</b> matching the number of solutions
*/
N_OF_SOLUTIONS Quad_Define_and_Solve(double a, double b, double c, double*x1, double*x2);

/// Solves ax^2+bx+c=0 considering a!=0
/**
\param double[in] <b>a, b, c</b>\n
Coefficients of a quadratic equation

\param double[out] <b>x1, x2</b>\n
Solutions of the equation. If number of roots is less than 2 all additional solutions remain unmodified

\return <b>enum N_OF_SOLUTIONS</b> matching the number of solutions
*/
N_OF_SOLUTIONS Solve_Full_Quad(double a, double b, double c, double* x1, double* x2);

/// Solves bx+c=0 considering b!=0
/**
\param double[in] <b>b, c</b>\n
Coefficients of a linear equation

\param double[out] <b>x1</b>\n
Solution of the equation

\return <b>ONE_SOLUTION</b>
*/
N_OF_SOLUTIONS Solve_Linear(double b, double c, double* x1);

/// Solves 0x+c=0
/**
\param double[in] c\n
Constant

\return <b>enum N_OF_SOLUTIONS</b> matching the number of solutions (is <b>INF_SOLUTIONS</b> in case c=0, is <b>NO_SOLUTIONS</b> otherwise)
*/
N_OF_SOLUTIONS Solve_Constant(double c);


N_OF_SOLUTIONS Quad_Define_and_Solve(double a, double b, double c, double* x1, double* x2)
{
    if (!Is_Zero(a))
        return Solve_Full_Quad(a, b, c, x1, x2);

    if (!Is_Zero(b))
        return Solve_Linear(b, c, x1);

    return Solve_Constant(c);
}

N_OF_SOLUTIONS Solve_Full_Quad(double a, double b, double c, double* x1, double* x2)
{
    double d = b*b - 4*a*c;
        if (Is_Zero(d)) {
            *x1 = (-b)/(2*a);
             return ONE_SOLUTION;
        }
        if (d > 0)  {
            double sqrt_d = sqrt(d);
            *x1 = (-b-sqrt_d)/(2*a);
            *x2 = (-b+sqrt_d)/(2*a);
            return TWO_SOLUTIONS;
        }
        return NO_SOLUTIONS;
}

N_OF_SOLUTIONS Solve_Linear(double b, double c, double* x1)
{
    *x1 = -c/b;
    return ONE_SOLUTION;
}

N_OF_SOLUTIONS Solve_Constant(double c)
{
    return ((Is_Zero(c))? INF_SOLUTIONS : NO_SOLUTIONS);
}
