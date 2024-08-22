#include <math.h>
#include "double_arithmetics.h"

bool Is_Zero(double a)
{
    return (fabs(a) < DOUBLE_DEVIATION);
}

bool Are_Equal(double a, double b)
{
    return Is_Zero(a-b);
}

double min(double a, double b)
{
    return ((a < b)? a : b);
}

double max(double a, double b)
{
    return ((a > b)? a : b);
}
