// Usage of cmatrix, the complex Matrix routines
#include"MatrixC.h"

int main()
{
     // Start random number generator 
     Rand_Open(0);
     // Size of matrices to be used
     long N=100;
     MatrixC A(N);
     
     // Generate a random self-adjoint matrix
     for (long i=1;i<=N;i++)
     {
	  A(i,i)=Rand();
	  for (long j=i+1;j<=N;j++)
	  {
	       A(i,j)=Rand()+M_I*Rand();
	       A(j,i)=conj(A(i,j));
	  }
     }
     // Now, diagonalize it!
     MatrixC Basis; Vector Eigen;
     A.Diagonalize(Basis,Eigen);
     MatrixC At=Basis*Diag(Eigen)*Herm(Basis);
     printf("Diagonalize Error: %16.12g\n",Norm(At-A));

     // Check the inverse matrix
     MatrixC Ainv=Invert(A);
     printf("Inverse error: %g\n",Norm(Ainv*A-Unit(N)));

     // Now, we build an arbitrary (non-hermitean) rectangular matrix
     // and check its singular value decomposition (SVD)
     long Na=4, Nb=3;
     MatrixC B(Na,Nb);
     for (long i=1;i<=Na;i++)
	  for (long j=1;j<=Nb;j++)
	       B(i,j)=Rand()+M_I*Rand();
    
     // Perform the SVD on it
     MatrixC U, V; Vector S;
     B.SVD(U,V,S);
     MatrixC Stot(Na,Nb);
     for (long i=1;i<=S.N;i++)
     	  Stot(i,i)=S(i);
     MatrixC B2=U*Stot*V;
     printf("SVD Error: %g\n",Norm(B2-B));
     Rand_Close();

}
