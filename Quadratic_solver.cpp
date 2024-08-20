#include <stdio.h>
#include <math.h>

const int INF_SOLUTIONS = -1;
#define abs(a) ((a > 0)? a:(-a))

int Solve_Quad(double a, double b, double c, double *x1, double *x2)
{
    if ( abs(a) > 1e-10) {
          double d = b*b - 4*a*c;
         if (abs(d) < 1e-10) {
               *x1 = (-b)/(2*a);
               return 1;
          }
          if (d > 1e-10)  {
               double sqrt_d = sqrt(d);
               *x1 = (-b+sqrt_d)/(2*a);
               *x2 = (-b-sqrt_d)/(2*a);
               return 2;
          }
          return 0;
    }

    if (abs(b) > 1e-10)  {
         *x1 = -c/b;
         return 1;
    }

    if (abs(c) > 1e-10)  {
        return 0;
    }
   return INF_SOLUTIONS;
}

int main()
{
    printf("Enter a, b, c\n");
    double a=0, b=0, c=0;
    scanf("%lg %lg %lg", &a, &b, &c);

    double x1=0, x2=0;
    int N_of_Solutions = Solve_Quad(a, b, c, &x1, &x2);
    switch (N_of_Solutions)
    {
        case 0: printf("No Solutions\n");
            break;
        case 1: printf("x1 = %lg\n", x1);
            break;
        case 2: printf("x1 = %lg, x2 = %lg\n", x1, x2);
            break;
        case INF_SOLUTIONS: printf("Any Number\n");
            break;
        default: printf("main(): Error, N_of_Solutions = %d\n", N_of_Solutions);
            return 1;
    }
    return 0;
}
















