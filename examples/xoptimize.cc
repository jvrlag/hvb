// 130130
// Checking optimization routines
#include"Optimize.h"

// The function to be optimized, it should always have two parameters:
// const Vector &X: the current position
// void *param: extra parameters passed to the function
double Function(const Vector &X, void *params)
{
     return Sqr(X(1)-10.0) + 0.3*Sqr(X(2)-5.0);
}

int main()
{
     Rand_Open(0);
     Vector X(2);
     long Ntimes=10000;
     double error, st;
     
     printf("Conjugated gradients:\n");
     st=Clock();
     for (long k=1;k<=Ntimes;k++) // optimize many times, to check
	  error=CG_Optimize(X,Function,NULL,1e-8);
     printf("Error: %g, Time: %g\n",error,Clock()-st);
     X.Write();
     X.Zero();

     printf("Powell:\n");
     st=Clock();
     for (long k=1;k<=Ntimes;k++)
	  error=Powell_Optimize(X,Function,NULL,1e-8);
     printf("Error: %g, Time: %g\n",error,Clock()-st);
     X.Write();
     X.Zero();
     
     printf("Steepest descent:\n");
     st=Clock();
     for (long k=1;k<=Ntimes;k++)
	  error=SD_Optimize(X,Function,NULL,1e-8);
     printf("Error: %g, Time: %g\n",error,Clock()-st);
     X.Write();
     X.Zero();

     printf("Annealing:\n");
     st=Clock();
     // Parameters: initial condition, function, parameters, annealing-data
     error=Annealing_Optimize(X,Function,NULL,NULL);
     printf("Error: %g, Time: %g\n",error,Clock()-st);
     X.Write();
}
