// 111019
// Program to show the graphics capabilities
#include"EX.h"

int main()
{
     // Start the graphics window, at point (100,100)
     long width=500, height=500;
     
     EX_Start(100,100,width,height);
     EX_Enable_Buffer();  // Avoids flickering in animations

     long kmax=100;
     for (long k=1;k<=kmax;k++)
     {
	  EX_Clear();
	  // Lines of increasing widths
	  EX_Color(k/(double)kmax,0,1-k/(double)kmax);  // RGB coordinates
	  for (long i=1;i<=5;i++)
	  {
	       EX_Set_Line_Width(k);
	       EX_Line(20*i,0,20*i,500);
	  }
	  // The shrinking hexagon
	  long N=6; List X(N), Y(N);
	  for (long i=1;i<=N;i++)
	  {
	       X(i)=300+(100+k)*cos(2.0*M_PI*i/(double)N);
	       Y(i)=300+(100-k)*sin(2.0*M_PI*i/(double)N);
	  }
	  EX_Color("yellow");
	  EX_Fill_Polygon(X,Y);

	  for (long i=1;i<=20;i++)
	  {
	       EX_Color(k/(double)kmax,sin(i),0);
	       EX_Fill_Circle(300+150.*sin((i+k)/10.),
			      100+(200.+5.*k)*cos(i/10.),i);
	  }

	  EX_Flush();
	  Delay(0.05);
     }
     EX_Read_Key();
    
     EX_Close();
}
