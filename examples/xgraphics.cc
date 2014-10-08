// 111019
// Program to show the graphics capabilities
#include"easyx.h"

int main()
{
     // Start the graphics window, at point (100,100)
     long width=500, height=500;
     
     EXStart(100,100,width,height);
     EXEnableBuffer();  // Avoids flickering in animations

     long kmax=100;
     for (long k=1;k<=kmax;k++)
     {
	  EXClear();
	  // Lines of increasing widths
	  EXColor(k/(double)kmax,0,1-k/(double)kmax);  // RGB coordinates
	  for (long i=1;i<=5;i++)
	  {
	       EXSetLineWidth(k);
	       EXLine(20*i,0,20*i,500);
	  }
	  // The shrinking hexagon
	  long N=6; List X(N), Y(N);
	  for (long i=1;i<=N;i++)
	  {
	       X(i)=300+(100+k)*cos(2.0*M_PI*i/(double)N);
	       Y(i)=300+(100-k)*sin(2.0*M_PI*i/(double)N);
	  }
	  EXColor("yellow");
	  EXFillPolygon(X,Y);

	  for (long i=1;i<=20;i++)
	  {
	       EXColor(k/(double)kmax,sin(i),0);
	       EXFillCircle(300+150.*sin((i+k)/10.),100+(200.+5.*k)*cos(i/10.),i);
	  }

	  EXFlush();
	  delay(0.05);
     }
     EXReadKey();
    
     EXClose();
}
