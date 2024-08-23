/**
\file
\brief
*/

/// Marks the amount of solutions
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


