#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "definitions.h"
#include "double_arithmetics.h"
#include "define_equation_and_solve.h"
#include "Tester.h"

int Run_All_Tests()
{
    Coefficients coeff = {0, 0, 0};
    Solution ethalon = {0, 0, UNDEFINED};

    FILE* test_set = fopen("Tester_data.txt", "r");
    assert(test_set != NULL); //"Could not open file"

    int n_of_tests;
    assert(fscanf(test_set, "%d", &n_of_tests)); //"Invalid number of tests"

    int i = 1;
    int succeded = 0, failed = 0;
    for (; i <= n_of_tests; i++)
    {
        if (!Get_Values(i, &coeff, &ethalon, test_set))
            return 1;

        if(!Run_Test(i, coeff, ethalon))
        {
            failed++;
            continue;
        }
        succeded++;
    }

    printf
    (
    "\nTotal number of done tests: %d/%d\n"
    "Succeded: %d, Failed: %d\n\n",
    (succeded + failed), n_of_tests, succeded, failed
    );
    fclose(test_set);

    return 0;
}

bool Run_Test(int test_i, Coefficients coeff, Solution ethalon)
{
    Solution solt = {0, 0, UNDEFINED};
    Quad_Define_and_Solve(coeff, &solt);

    bool value_check = Are_Equal(min(solt.x1, solt.x2), min(ethalon.x1, ethalon.x2)) &&
                       Are_Equal(max(solt.x1, solt.x2), max(ethalon.x1, ethalon.x2));
    bool number_check = (solt.n_roots == ethalon.n_roots);

    if (!value_check || !number_check)
    {
        printf
        (
        "\nTest №%d failed!\n"
        "a = %lg, b = %lg, c = %lg -> x1 = %lg, x2 = %lg, roots_number = %d\n"
        "Expected: x1 = %lg, x2 = %lg, roots_number = %d\n",
        test_i, coeff.a, coeff.b, coeff.c, solt.x1, solt.x2, solt.n_roots,
        ethalon.x1, ethalon.x2, ethalon.n_roots
        );
        return 0;
    }
    printf ("\nTest %d succeded!\n", test_i);
    return 1;
}

bool Get_Values(int i, Coefficients *coeff, Solution *ethalon, FILE* test_set)
{

    if (fscanf(test_set, "%lg%lg%lg%lg%lg%d", &(coeff->a), &(coeff->b), &(coeff->c), &(ethalon->x1), &(ethalon->x2), &(ethalon->n_roots)) != 6)
    {
        printf("\nReading error in test %d\n", &i);
        return 0;
    }

    return 1;
}
