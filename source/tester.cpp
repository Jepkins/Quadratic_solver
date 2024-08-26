#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "..\lib\definitions.h"
#include "..\lib\double_arithmetics.h"
#include "..\lib\equation.h"
#include "..\lib\tester.h"


int run_all_tests(FILE *output_stream)
{
    Test_Conditions test_set[] = {{{   2,    3,       -5}, {-2.5, 1, TWO_SOLUTIONS}},
                                  {{   0,    0,        0}, {   0, 0, INF_SOLUTIONS}},
                                  {{   0,    0,        5}, {   0, 0,  NO_SOLUTIONS}},
                                  {{   3,    3,        3}, {   0, 0,  NO_SOLUTIONS}},
                                  {{   0,    3,        6}, {  -2, 0,  ONE_SOLUTION}},
                                  {{  -2,    3,       -1}, { 0.5, 1, TWO_SOLUTIONS}},
                                  {{   5,    0,       -5}, {  -1, 1, TWO_SOLUTIONS}},
                                  {{   1,    4,        4}, {  -2, 0,  ONE_SOLUTION}},
                                  {{   4,    4,       -8}, {  -2, 1, TWO_SOLUTIONS}},
                                  {{  -1,    5,     -100}, {   0, 0,  NO_SOLUTIONS}},
                                  {{  -1,    5, INFINITY}, {   0, 0,   INPUT_ERROR}},
                                  {{1e30, 2e30,     1e30}, {  -1, 0,  ONE_SOLUTION}}};


    const int n_of_tests = sizeof(test_set) / sizeof(test_set[0]);

    int succeded = 0, failed = 0;
    for (int i = 1; i <= n_of_tests; i++)
    {
        if(!run_test(i, test_set[i-1].coeff, test_set[i-1].solt_expected, output_stream))
        {
            failed++;
            continue;
        }

        succeded++;
    }

    fprintf(
        output_stream,
        "\nTotal number of done tests: %d/%d\n"
        "Succeded: %d, Failed: %d\n\n",
        (succeded + failed), n_of_tests, succeded, failed
    );

    return 0;
}

bool run_test(int test_i, Coefficients coeff, Solution ethalon, FILE *output_stream)
{
    Solution solt = {0, 0, UNDEFINED};
    solve_full_quad(coeff.a, coeff.b, coeff.c, &solt);

    bool value_check = are_equal(min(solt.x1, solt.x2), min(ethalon.x1, ethalon.x2)) &&
                       are_equal(max(solt.x1, solt.x2), max(ethalon.x1, ethalon.x2));
    bool number_check = (solt.n_roots == ethalon.n_roots);

    if (!value_check || !number_check)
    {
        fprintf(
            output_stream,
            "\nTest %d failed!\n"
            "a = %lg, b = %lg, c = %lg -> x1 = %lg, x2 = %lg, roots_number = %d\n"
            "Expected: x1 = %lg, x2 = %lg, roots_number = %d\n",
            test_i, coeff.a, coeff.b, coeff.c, solt.x1, solt.x2, solt.n_roots,
            ethalon.x1, ethalon.x2, ethalon.n_roots
        );
        return 0;
    }
    fprintf (output_stream, "\nTest %d succeded!\n", test_i);
    return 1;
}

