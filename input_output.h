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
