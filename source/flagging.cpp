#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "..\lib\definitions.h"
#include "..\lib\flagging.h"

bool set_run_flags(GETOPT_RETS opt_flag, getopt_out opt_out, RUN_CONDITIONS *run_conds)
{
    switch (opt_flag)
    {
        case OPT_FOUND:
        {
            if (!strcmp(opt_out.opt, "-r") || !strcmp(opt_out.opt, "--run"))
            {
                if (run_conds->mode != RELEASE && run_conds->mode != DEFAULT)
                {
                    printf("Can not set multiple run modes! (Do not use -r, -t simultaneously)\n");
                    return 0;
                }
                run_conds->mode = RELEASE;
                return 1;
            }

            if (!strcmp(opt_out.opt, "-t") || !strcmp(opt_out.opt, "--test"))
            {
                if (run_conds->mode != TESTING && run_conds->mode != DEFAULT)
                {
                    printf("Can not set multiple run modes! (Do not use -r, -t simultaneously)\n");
                    return 0;
                }
                run_conds->mode = TESTING;
                return 1;
            }

            if (!strcmp(opt_out.opt, "-i") || !strcmp(opt_out.opt, "--input-file"))
            {
                if (run_conds->do_file_input == true)
                {
                    printf("Can not select multiple files for input! (Do not use multiple -i, --input-file)\n");
                    return 0;
                }

                run_conds->do_file_input = true;
                run_conds->input_file = opt_out.optarg;

                return 1;
            }

            if (!strcmp(opt_out.opt, "-o") || !strcmp(opt_out.opt, "--output-file"))
            {
                if (run_conds->do_file_output == true)
                {
                    printf("Can not select multiple files for output! (Do not use multiple -o, --output-file)\n");
                    return 0;
                }

                run_conds->do_file_output = true;
                run_conds->output_file = opt_out.optarg;
                return 1;
            }

            assert(0); // opt found in optstring but not in set_run_flags()
        }

        case NOT_AN_OPT:
        {
            printf(
                "Expected option: %s\n"
                "                 ^\n"
                "                 |\n"
                "                 here\n",
                opt_out.opt
            );
            return 0;
        }

        case OPT_UNKNOWN:
        {
            printf("Unknown option: %s\n", opt_out.opt);
            return 0;
        }

        case EXPECTED_ARG:
        {
            printf(
            "Expected argument: %s |<- here\n",
            opt_out.opt
            );
            return 0;
        }

        case ARGV_END:
        default:
        {
            assert(0); // incorrect opt_flag
        }

    }
}
