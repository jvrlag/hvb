// Usage of cmatrix, the complex Matrix routines
#include"cmatrix.h"

int main()
{
     // Start random number generator 
     open_rng(0);
     // Size of matrices to be used
     long N=100;
     CMatrix A(N);
     
     // Generate a random self-adjoint matrix
     for (long i=1;i<=N;i++)
     {
	  A(i,i)=rand_double();
	  for (long j=i+1;j<=N;j++)
	  {
	       A(i,j)=rand_double()+M_I*rand_double();
	       A(j,i)=conj(A(i,j));
	  }
     }
     // Now, diagonalize it!
     CMatrix Basis; Vector Eigen;
     A.Diagonalize(Basis,Eigen);
     CMatrix At=Basis*Diag(Eigen)*Herm(Basis);
     printf("Diagonalize Error: %16.12g\n",Frobenius_Norm(At-A));

     // Check the inverse matrix
     CMatrix Ainv=Invert(A);
     printf("Inverse error: %g\n",Frobenius_Norm(Ainv*A-Unit(N)));

     // Now, we build an arbitrary (non-hermitean) rectangular matrix
     // and check its singular value decomposition (SVD)
     long Na=4, Nb=3;
     CMatrix B(Na,Nb);
     for (long i=1;i<=Na;i++)
	  for (long j=1;j<=Nb;j++)
	       B(i,j)=rand_double()+M_I*rand_double();
    
     // Perform the SVD on it
     CMatrix U, V; Vector S;
     B.SVD(U,V,S);
     CMatrix Stot(Na,Nb);
     for (long i=1;i<=S.N;i++)
     	  Stot(i,i)=S(i);
     CMatrix B2=U*Stot*V;
     printf("SVD Error: %g\n",Frobenius_Norm(B2-B));
     close_rng();

}
