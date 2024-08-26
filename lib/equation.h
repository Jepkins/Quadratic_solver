/**
\file
\brief Provides functions for solving up to 2nd degree polynominal equations
*/

#ifndef EQUATION_H
#define EQUATION_H


/// Solves ax^2+bx+c=0
/**
\param[in] double \b a, \b b, \b c
Parameters of the equation
\param[out] Solution* \b solt
Solutions of the equation
*/
void solve_full_quad(double a, double b, double c, Solution *solt);

/// Solves bx+c=0
/**
\param[in] double \b b, \b c
Parameters of the equation
\param[out] Solution* \b solt
Solutions of the equation
*/
void solve_linear(double b, double c, Solution *solt);

/// Solves 0x+c=0
/**
\param[in] double \b c
Parameter of the equation
\param[out] Solution* \b solt
Solutions of the equation
*/
void solve_constant(double c, Solution *solt);

#endif // EQUATION_H

