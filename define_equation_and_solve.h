/**
\file
\brief Provides functions for solving up to 2nd degree polynominal equations
*/

/// Defines the type of equation and passes on to the solving functions
/**

*/
void Quad_Define_and_Solve(Coefficients coeff, Solution *solt);

/// Solves ax^2+bx+c=0 considering a!=0
/**

*/
void Solve_Full_Quad(double a, double b, double c, Solution *solt);

/// Solves bx+c=0 considering b!=0
/**

*/
void Solve_Linear(double b, double c, Solution *solt);

/// Solves 0x+c=0
/**

*/
void Solve_Constant(double c, Solution *solt);


