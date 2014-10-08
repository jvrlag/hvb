// 060510
// Checking the image library
#include"easyim.h"

int main()
{
     int xsize=600;
     // Start the Xwindow
     EXStart(100,100,xsize,xsize);
     // Double-buffer capabilities, make motion smooth
     EXEnableBuffer();
     // Start Image server
     EI_Start();
     // Load image
     EI_Load("extra_files/danae.jpg");

     for (int i=1;i<=xsize;i+=2)
     {
	  EXClear();
	  // Render the current image
	  EI_Render_Scaled(xsize/2-i/2,xsize/2-i/2,i,i);
	  // Do some drawing on top
	  long kmax=i;
	  for (long k=1;k<=kmax;k++)
	  {
	       double factor=sqr(sin(k/(double)kmax));
	       EXColor(factor,1-factor,factor/10.0);
	       EXLine(0,k,xsize,xsize-k);
	  }
	  EXFlush(); // do not forget this!
	  delay(0.01);
     }
     EXReadKey();
     EXClose();

}
