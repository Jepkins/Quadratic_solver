/**
\file
\brief Provides means of testing equation.h functions
*/

#ifndef TESTER_H
#define TESTER_H

/// Runs a test with set conditions and outputs details in case of a failure
/**
\param[in] int \b test_i
Test number
\param[in] Coefficients \b coeff
Parameters of the equation for the test
\param[in] Solution \b ethalon
Solutions expected from the solving unit
\return \b 1 if test is successful
\return \b 0 if test failed
*/
bool run_test(int test_i, Coefficients coeff, Solution ethalon, FILE *output_stream);


/// Initializes tests and shows the results
int run_all_tests(FILE *output_stream);

#endif // TESTER_H
