/**
\file
\brief Executes input/output from/to cmd or other selected stream
*/

#ifndef INPUT_OUTPUT_H
#define INPUT_OUTPUT_H

/// Custom version of standart unistd.h getopt() function
/**
\param[in] int \b argc
The number of cmd arguments for main()
\param[out] char* \b argv[]
Pointer to arguments line
\param[out] char* \b optstring
Pointer to acceptable options line
\param[out] getopt_out* \b opt_out
Pointer to getopt_out structure containing option itself, option index and its argument

*/
GETOPT_RETS getopt_custom(int argc, char * const argv[], const char* optstring, getopt_out* opt_out);

/// Gets an argument for an option getopt_custom() is currently proccessing
GETOPT_RETS getoptarg(int argc, char * const argv[], getopt_out* opt_out);


/// Asks user to input coefficients of a quadratic equation
/**
\param[out] Coefficients* \b coeff
Coefficients for reading
\param[in] bool \n do_file_input
If true, runs in file reading mode
\return \b 0 in case of error
\return \b 1 in case of successful input
*/
bool input_coefficients(Coefficients *coeff, bool do_file_input, FILE* input_stream, FILE* output_stream);

/// Outputs the solutions of a quadratic equation
/**
\param[in] Solution \b solt
Solutions to output
\return \b 0 in case of successful printing
\return \b 1 in case of invalid solt.roots_number value
*/
bool output_roots(Solution solt, FILE* output_stream);

/// Clears input stream
/**
\return \b -1 in case of error
\return \b 0 in case of invalid input
\return \b 1 in case of success
*/
int clear_buffer(FILE* input_stream);

#endif // INPUT_OUTPUT_H
