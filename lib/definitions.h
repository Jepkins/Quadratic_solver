/**
\file
\brief Structures and enumerations declaration
*/

#ifndef DEFINITIONS_H
#define DEFINITIONS_H



struct getopt_out {
    char* opt;
    char* optarg;
    int optind;
};

enum RUN_MODE {
    RELEASE = 1,
    TESTING = 2,
    DEFAULT = 0
};

struct RUN_CONDITIONS {
    enum RUN_MODE mode;

    bool do_file_input;
    char* input_file;

    bool do_file_output;
    char* output_file;
};

enum GETOPT_RETS {
    ARGV_END = -10,
    NOT_AN_OPT = -1,
    OPT_UNKNOWN = -2,
    EXPECTED_ARG = -3,
    OPT_FOUND = 1
};


enum N_OF_SOLUTIONS {
    NO_SOLUTIONS  = 0,
    ONE_SOLUTION  = 1,
    TWO_SOLUTIONS = 2,
    INF_SOLUTIONS = -1,
    INPUT_ERROR = -2,
    UNDEFINED = -10
};

struct Coefficients {
    double a, b, c;
};

struct Solution {
    double x1, x2;
    N_OF_SOLUTIONS n_roots;
};

struct Test_Conditions {
    Coefficients coeff;
    Solution solt_expected;
};

#endif // DEFINITIONS_H
