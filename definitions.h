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
    Solution expected;
};


