/**
\file
\brief Provides means of comparing floating point values concerning deviation due to calculating errors
*/

/// Maximum difference between floating point values for them to be considered equal
const double DOUBLE_DEVIATION = 1e-20;

/// Defines whether a floating point is zero
/**
\param double[in] \b a

\return \b true if a=0, \b false otherwise
*/
bool Is_Zero(double a);

/// Defines whether floating point values are equal
/**
\param double[in] <b>a, b</b>

\return \b true if a=b, \b false otherwise
*/
bool Are_Equal(double a, double b);

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


