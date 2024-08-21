/**
\file

\brief Executes tests for Quad_Define_and_Solve() of "define_equation_and_solve.h"

This program reads test conditions from "Tester_data.txt", which contains them in the following form:\n
First row contains 1 number - number of tests\n
All of the following rows contain coefficients of polynominal equations ax^2+bx+c=0 and their solutions in the following order\n
a b c x1 x2 number_of_roots\n
Notice: if number of roots is less than 2 all additional solutions are set to 0.\n
\warning Make sure that "Tester_data.txt" contains valid tests

Program displays results of each test and outputs numbers of succesful and failed ones.
*/

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "..\\flagging.h"
#include "..\\double_arithmetics.h"
#include "..\\define_equation_and_solve.h"

/// Runs a test with set conditions and outputs details in case of a failure
/**
\param <b>int[in] test_i</b>\n
test number
\param double[in] <b>a, b, c</b>\n
Coefficients of a quadratic equation
\param double[in] <b>x1, x2</b>\n
Expected solutions of a quadratic equation (order is irrelevant). If number of roots is less than 2 all additional solutions are set to 0
\param N_OF_SOLUTIONS[in] <b>roots_number_correct</b>\n
Expected number of solutions
\return \b true if test is successful
\return \b false if test failed
*/
bool Run_Test(int test_i, double a, double b, double c, double x1_correct, double x2_correct, N_OF_SOLUTIONS roots_number_correct);

/// Reads current test conditions from the file
/**
\param int[in] <b>test_i</b>\n
test number
\param double[out] <b>a, b, c</b>\n
Coefficients of a quadratic equation
\param double[out] <b>x1, x2</b>\n
Expected solutions of a quadratic equation (order is irrelevant). If number of roots is less than 2 all additional solutions are set to 0
\param N_OF_SOLUTIONS[out] <b>roots_number_correct</b>\n
Expected number of solutions
\return \b true if reading is successful
\return \b false if reading failed
*/
bool Get_Values(int i, double* a, double* b, double* c, double* x1_correct, double* x2_correct, N_OF_SOLUTIONS* roots_number_correct, FILE* test_set);


/// Initializes tests and shows the results
int main()
{
    double a = 0, b = 0, c = 0;
    double x1_correct = 0, x2_correct = 0;
    enum N_OF_SOLUTIONS roots_number_correct = UNDEFINED;

    FILE* test_set = fopen("Tester_data.txt", "r");
    assert(test_set != NULL); //"Could not open file"

    int n_of_tests;
    assert(fscanf(test_set, "%d", &n_of_tests)); //"Invalid number of tests"

    int i = 1;
    int succeded = 0, failed = 0;
    for (; i <= n_of_tests; i++)
    {
        if (!Get_Values(i, &a, &b, &c, &x1_correct, &x2_correct, &roots_number_correct, test_set))
            return 1;

        if(!Run_Test(i, a, b, c, x1_correct, x2_correct, roots_number_correct))
        {
            failed++;
            continue;
        }
        succeded++;
    }

    printf
    (
    "\nTotal number of done tests: %d/%d\n"
    "Succeded: %d, Failed: %d\n",
    (succeded + failed), n_of_tests, succeded, failed
    );
    fclose(test_set);

    return 0;
}

bool Run_Test(int test_i, double a, double b, double c, double x1_correct, double x2_correct, N_OF_SOLUTIONS roots_number_correct)
{
    double x1 = 0, x2 = 0;
    enum N_OF_SOLUTIONS roots_number = Quad_Define_and_Solve(a, b, c, &x1, &x2);

    bool value_check = Are_Equal(std::min(x1, x2), std::min(x1_correct, x2_correct)) && Are_Equal(std::max(x1, x2), std::max(x1_correct, x2_correct));
    bool number_check = (roots_number == roots_number_correct);

    if (!value_check || !number_check)
    {
        printf
        (
        "\nTest №%d failed!\n"
        "a = %lg, b = %lg, c = %lg -> x1 = %lg, x2 = %lg, roots_number = %d\n"
        "Expected: x1 = %lg, x2 = %lg, roots_number = %d\n",
        test_i, a, b, c, x1, x2, roots_number,
        x1_correct, x2_correct, roots_number_correct
        );
        return 0;
    }
    printf ("\nTest №%d succeded!\n", test_i);
    return 1;
}

bool Get_Values(int i, double* a, double* b, double* c, double* x1_correct, double* x2_correct, N_OF_SOLUTIONS* roots_number_correct, FILE* test_set)
{

    if (fscanf(test_set, "%lg%lg%lg%lg%lg%d", a, b, c, x1_correct, x2_correct, roots_number_correct) != 6)
    {
        printf("\nReading error in test %d\n", &i);
        return 0;
    }

    return 1;
}
