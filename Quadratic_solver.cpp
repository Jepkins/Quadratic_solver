/**
\file
\brief Program solving up to 2nd degree polynominal equations

This program asks user to enter 3 coefficients of a quadratic equation and outputs all of its roots
*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include "definitions.h"
#include "double_arithmetics.h"
#include "define_equation_and_solve.h"
#include "Tester.h"
#include "input_output.h"


/// Initializes input, proccessing and output
/*
-r to run main program
-t to run unit tester
*/

int main(int argc, char *argv[])
{
   int c;
   bool solver_run = 0, tester_run = 0;

   while (--argc > 0 && (*++argv)[0] == '-')
       while ((c = *++argv[0]))
           switch (c)
           {
           case 'r':
               solver_run = 1;
               break;
           case 't' :
               tester_run = 1;
               break;
           default :
               printf( "Incorrect parameter: %d\n", c);
               argc = -1;
               break;
           }

   if (argc != 0)
   {
   printf("Use -r -t -rt\n");
   return 1;
   }

   if (tester_run)
   {
   Run_All_Tests();
   }

   if (solver_run)
   {
   Coefficients coeff = {0, 0, 0};
   Input_Coefficients(&coeff);

   Solution solt = {0, 0, UNDEFINED};
   Quad_Define_and_Solve(coeff, &solt);

   Output_Roots(solt);
  }

   return 0;
}






















