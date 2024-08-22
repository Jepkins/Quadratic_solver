/**
\file

\brief Executes tests for Quad_Define_and_Solve() of "define_equation_and_solve.h"

Reads test conditions from "Tester_data.txt", which contains them in the following form:\n
First row contains 1 number - number of tests\n
All of the following rows contain coefficients of polynominal equations ax^2+bx+c=0 and their solutions in the following order\n
a b c x1 x2 number_of_roots\n
Notice: if number of roots is less than 2 all additional solutions are set to 0.\n
\warning Make sure that "Tester_data.txt" contains valid tests

Program displays results of each test and outputs numbers of succesful and failed ones.
*/


/// Runs a test with set conditions and outputs details in case of a failure
/**

*/
bool Run_Test(int test_i, Coefficients coeff, Solution ethalon);

/// Reads current test conditions from the file
/**

*/
bool Get_Values(int i, Coefficients *coeff, Solution *ethalon, FILE* test_set);


/// Initializes tests and shows the results
int Run_All_Tests();
