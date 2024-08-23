/**
\file
\brief Provides means of comparing floating point values concerning deviation due to calculating errors
*/


/// Defines whether a floating point is zero
/**
\param[in] double \b a

\return \b true if a=0, \b false otherwise
*/
bool Is_Zero(double a);

/// Defines whether floating point values are equal
/**
\param[in] double <b>a, b</b>

\return \b true if a=b, \b false otherwise
*/
bool Are_Equal(double a, double b);

double min(double a, double b);

double max(double a, double b);


