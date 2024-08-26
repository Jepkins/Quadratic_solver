#include <stdio.h>
#include <math.h>
#include <string.h>
#include "..\lib\definitions.h"
#include "..\lib\equation.h"
#include "..\lib\tester.h"
#include "..\lib\input_output.h"
#include "..\lib\flagging.h"


/// Initializes input, proccessing and output
/*
-r, --run to run main program
-t, --test to run unit tester
-i <filename>, --input-file <filename> to set input stream to "filename"
-o <filename>, --output-file <filename> to set output stream to "filename"
*/

int main(int argc, char *argv[])
{
    const char *optstring = " -r -t -i: -o: --run --test --input-file: --output-file: ";
    // !!! always starts and ends with ' ', short options must be before long ones, do not use ':' in option names

    if (argc == 1) {
        printf(
        "Expected options. Use:\n"
        "-r, --run to run main program\n"
        "-t, --test to run unit tester\n"
        "-i <filename>, --input-file <filename> to set input stream to filename\n"
        "-o <filename>, --output-file <filename> to set output stream to filename\n"
        );
        return 0;
    }


    struct getopt_out opt_out = {.optind = 1};

    struct RUN_CONDITIONS run_conds = {.mode = DEFAULT, .do_file_input = 0, .do_file_output = 0};

    enum GETOPT_RETS opt_flag = ARGV_END;

    while ((opt_flag = getopt_custom(argc, argv, optstring, &opt_out)) != ARGV_END)
    {
        if (!set_run_flags(opt_flag, opt_out, &run_conds))
            return 1;
    }

    if (run_conds.mode == DEFAULT)
    {
        printf("Usage of -r or -t is required\n");
        return 1;
    }

    FILE *input_stream = stdin, *output_stream = stdout;
    if (run_conds.do_file_input)
    {
        input_stream = fopen(run_conds.input_file, "r");
    }
    if (run_conds.do_file_output)
    {
        output_stream = fopen(run_conds.output_file, "w");
    }

    if (run_conds.mode == TESTING)
    {
        run_all_tests(output_stream);
    }


    if (run_conds.mode == RELEASE)
    {
        Coefficients coeff = {0, 0, 0};

        if (!input_coefficients(&coeff, run_conds.do_file_input, input_stream, output_stream))
            return 1;

        Solution solt = {0, 0, UNDEFINED};
        solve_full_quad(coeff.a, coeff.b, coeff.c, &solt);

        output_roots(solt, output_stream);
    }


    if (run_conds.do_file_input)
    {
        fclose(input_stream);
    }
    if (run_conds.do_file_output)
    {
        fclose(output_stream);
    }

    return 0;
}
