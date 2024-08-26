/**
\file
\brief Sets flags using getopt options
*/

#ifndef FLAGGING_H
#define FLAGGING_H

/// Sets run configurations
/**
\param[in] GETOPT_RETS \b opt_flag
The return value of getopt_custom()
\param[in] getopt_out \b opt_out
The structure modified in getopt_custom()
\param[out] RUN_CONDITIONS* \b run_conds
Pointer to run setup structure
\return 1 in case of successful setting
\return 0 in case of error
*/
bool set_run_flags(GETOPT_RETS opt_flag, getopt_out opt_out, RUN_CONDITIONS *run_conds);

#endif // FLAGGING_H
