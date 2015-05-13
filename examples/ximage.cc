// 060510
// Checking the image library
#include"Image.h"

int main()
{
     int xsize=600;
     // Start the Xwindow
     EX_Start(100,100,xsize,xsize);
     // Double-buffer capabilities, make motion smooth
     EX_Enable_Buffer();
     // Start Image server
     EI_Start();
     // Load image
     EI_Load("extra_files/danae.jpg");

     for (int i=1;i<=xsize;i+=2)
     {
	  EX_Clear();
	  // Render the current image
	  EI_Render_Scaled(xsize/2-i/2,xsize/2-i/2,i,i);
	  // Do some drawing on top
	  long kmax=i;
	  for (long k=1;k<=kmax;k++)
	  {
	       double factor=Sqr(sin(k/(double)kmax));
//	       EX_Color(factor,1-factor,factor/10.0);
	       EX_Line(0,k,xsize,xsize-k);
	  }
	  EX_Flush(); // do not forget this!
	  Delay(0.01);
     }
     EX_Read_Key();
     EX_Close();

}
