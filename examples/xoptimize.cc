// 130130
// Checking optimization routines
#include"optimize.h"

// The function to be optimized, it should always have two parameters:
// const Vector &X: the current position
// void *param: extra parameters passed to the function
double Function(const Vector &X, void *params)
{
     return sqr(X(1)-10.0) + 0.3*sqr(X(2)-5.0);
}

int main()
{
     open_rng(0);
     Vector X(2);
     long Ntimes=10000;
     double error, st;
     
     printf("Conjugated gradients:\n");
     st=uhr();
     for (long k=1;k<=Ntimes;k++) // optimize many times, to check
	  error=CG_Optimize(X,Function,NULL,1e-8);
     printf("Error: %g, Time: %g\n",error,uhr()-st);
     X.Write();
     X.Zero();

     printf("Powell:\n");
     st=uhr();
     for (long k=1;k<=Ntimes;k++)
	  error=Powell_Optimize(X,Function,NULL,1e-8);
     printf("Error: %g, Time: %g\n",error,uhr()-st);
     X.Write();
     X.Zero();
     
     printf("Steepest descent:\n");
     st=uhr();
     for (long k=1;k<=Ntimes;k++)
	  error=SD_Optimize(X,Function,NULL,1e-8);
     printf("Error: %g, Time: %g\n",error,uhr()-st);
     X.Write();
     X.Zero();

     printf("Annealing:\n");
     st=uhr();
     // Parameters: initial condition, function, parameters, annealing-data
     error=Annealing_Optimize(X,Function,NULL,NULL);
     printf("Error: %g, Time: %g\n",error,uhr()-st);
     X.Write();
}
