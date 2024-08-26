#include <math.h>
#include "..\lib\double_arithmetics.h"

bool is_zero(double a)
{
    return (fabs(a) < DOUBLE_DEVIATION);
}

bool are_equal(double a, double b)
{
    return is_zero(a-b);
}

double min(double a, double b)
{
    return ((a < b)? a : b);
}

double max(double a, double b)
{
    return ((a > b)? a : b);
}
