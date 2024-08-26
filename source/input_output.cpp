#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "..\lib\definitions.h"
#include "..\lib\input_output.h"


GETOPT_RETS getopt_custom(int argc, char * const argv[], const char *optstring, getopt_out* opt_out)
{
    if (opt_out->optind > argc - 1)
        return ARGV_END;

    char* word = *(argv + opt_out->optind++);
    opt_out->opt = word;

    size_t word_length = strlen(word);


    if (word_length < 2)
        return NOT_AN_OPT;

    if (word[0] != '-' || !strcmp(word, "--") || (word_length > 2 && word[1] != '-'))
        return NOT_AN_OPT;


    char* opt_pointer = strstr(optstring, word);

    if (opt_pointer == NULL || opt_pointer[-1] != ' ' || (opt_pointer[word_length] != ':' && opt_pointer[word_length] != ' '))
        return OPT_UNKNOWN;


    if (opt_pointer[word_length] == ':')
        return getoptarg(argc, argv, opt_out);

    return (OPT_FOUND);
}

GETOPT_RETS getoptarg(int argc, char * const argv[], getopt_out* opt_out)
{
    if (opt_out->optind > argc - 1)
        return EXPECTED_ARG;

    if (*(argv + opt_out->optind)[0] == '-')
        return EXPECTED_ARG;

    opt_out->optarg = *(argv + opt_out->optind++);

    return OPT_FOUND;
}

bool input_coefficients(Coefficients *coeff, bool do_file_input, FILE* input_stream, FILE* output_stream)
{
    double a = NAN, b = NAN, c = NAN;
    if (!do_file_input)
        printf("Enter a, b, c\n");

    int d = 0;

    while ( ((d = fscanf(input_stream, "%lg %lg %lg", &a, &b, &c)) != 3)  || !(isfinite(a) && isfinite(b) && isfinite(c)))
    {
        if (do_file_input)
        {
            fprintf(output_stream, "Incorrect input\n");
            return 0;
        }

        printf("Incorrect input\n\n");

        if (clear_buffer(input_stream) == -1)
        {
            return 0;
        }

        printf("Enter a, b, c\n");
    }

    if (do_file_input)
    if (clear_buffer(input_stream) != 1)
    {
        fprintf(output_stream, "Incorrect input\n\n");
        return 0;
    }

    if (!do_file_input)
    if (clear_buffer(input_stream) == 0 )
    {
        fprintf(input_stream, "Incorrect input\n\n");
        return input_coefficients(coeff, do_file_input, input_stream, output_stream);
    }

    coeff->a = a;
    coeff->b = b;
    coeff->c = c;
    return 1;
}

int clear_buffer(FILE* input_stream)
{
    int a = 0;
    bool nonspace_met = 0;
    while ((a = fgetc(input_stream)) != '\n')
    {
        if (a == EOF)
        {
            return -1;
        }

        if (!isspace(a))
        {
            nonspace_met = 1;
        }

        if (a == '\x1a')
        {
            return 0;
        }

    }

    if (nonspace_met)
        return 0;

    return 1;
}

bool output_roots(Solution solt, FILE* output_stream)
{
    switch (solt.n_roots)
    {
    case NO_SOLUTIONS:  fprintf(output_stream, "No Solutions\n");                         break;
    case ONE_SOLUTION:  fprintf(output_stream, "x1 = %lg\n", solt.x1);                    break;
    case TWO_SOLUTIONS: fprintf(output_stream, "x1 = %lg, x2 = %lg\n", solt.x1, solt.x2); break;
    case INF_SOLUTIONS: fprintf(output_stream, "Any Number\n");                           break;

    case INPUT_ERROR: fprintf(output_stream, "Input Error!\n");
	 	return 1;

    case UNDEFINED:
    default:
        fprintf(output_stream, "Error, n_roots = %d\n", solt.n_roots);
        return 1;
    }
    return 0;
}
