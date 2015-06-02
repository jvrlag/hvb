////////////////////////////////////////////////////////
// hvb++ 1.0
// Copyleft: Javier Rodr�guez Laguna
// 080725-141121
// Simple driver to create PostScript graphics from C
// Headers
// JaviRL, 0004, 0208, 0505, 0607
#ifndef EASYPS
#define EASYPS
#include"Postscript.h"

FILE *PS_Current_File=NULL;

FILE *PS_Open(const char *name,int x0, int y0, int x1, int y1)
{
     FILE *psfile;
     psfile=fopen(name,"wt");
     if (psfile==NULL) 
     {
	  printf("Error opening file %s\n",name);
	  exit(1);
     }
     fprintf(psfile,"%%!PS-Adobe-2.0\n");
     fprintf(psfile,"%%%%Title: %s\n",name);
     fprintf(psfile,"%%%%Creator: EasyPS version 140304\n");
     fprintf(psfile,"%%%%BoundingBox: %d %d %d %d\n",x0,y0,x1,y1);
     fprintf(psfile,"%%%%EndComments\n");
     fprintf(psfile,"/n {newpath} def /m {moveto} def /l {lineto} def\n");
     fprintf(psfile,"/s {stroke} def /sl {setlinewidth} def \n");
     fprintf(psfile,"/sr {setrgbcolor} def /sg {setgray} def /f {fill} def\n");
     fprintf(psfile,"/a {0 360 arc} def /c {closepath} def ");
     fprintf(psfile,"/sd {setdash} def\n");
     fprintf(psfile,"0.2 sl\n");
     PS_Current_File=psfile;
     return psfile;
}

void PS_Close(FILE *psfile)
{
     fprintf(psfile,"showpage\n");
     fclose(psfile);
}

void PS_Translate(FILE *psfile, double x, double y)
{
     fprintf(psfile,"%.4g %.4g translate\n",x,y);
}

void PS_Translate(double x, double y)
{
     PS_Translate(PS_Current_File,x,y);
}

void PS_Line(FILE *psfile, double x0, double y0, double x1, double y1)
{
     fprintf(psfile,"n\n");
     fprintf(psfile,"%.4g %.4g m\n",x0,y0);
     fprintf(psfile,"%.4g %.4g l\n",x1,y1);
     fprintf(psfile,"s\n");
}

void PS_Line(double x0, double y0, double x1, double y1)
{
     PS_Line(PS_Current_File,x0,y0,x1,y1);
}

void PS_Circle(FILE *psfile, double cx0, double cy0, double R)
{
     fprintf(psfile,"n\n");
     fprintf(psfile,"%.4g %.4g %.4g a\n",cx0,cy0,R);
     fprintf(psfile,"s\n");
}

void PS_Circle(double cx0, double cy0, double R)
{
     PS_Circle(PS_Current_File,cx0,cy0,R);
}

void PS_Fill_Circle(FILE *psfile, double cx0, double cy0, double R)
{
     fprintf(psfile,"n\n");
     fprintf(psfile,"%.4g %.4g %.4g a\n",cx0,cy0,R);
     fprintf(psfile,"f\n");
}

void PS_Fill_Circle(double cx0, double cy0, double R)
{
     PS_Fill_Circle(PS_Current_File,cx0,cy0,R);
}

void PS_Rectangle(FILE *psfile, double x0, double y0, double wx, double wy)
{
     fprintf(psfile,"n\n");
     fprintf(psfile,"%.4g %.4g m\n",x0,y0);
     fprintf(psfile,"%.4g %.4g l\n",x0+wx,y0);
     fprintf(psfile,"%.4g %.4g l\n",x0+wx,y0+wy);
     fprintf(psfile,"%.4g %.4g l\n",x0,y0+wy);
     fprintf(psfile,"c\n");
     fprintf(psfile,"s\n");
}

void PS_Rectangle(double x0, double y0, double wx, double wy)
{
     PS_Rectangle(PS_Current_File,x0,y0,wx,wy);
}

void PS_Fill_Rectangle(FILE *psfile, double x0, double y0, double wx, double wy)
{
     fprintf(psfile,"n\n");
     fprintf(psfile,"%.4g %.4g m\n",x0,y0);
     fprintf(psfile,"%.4g %.4g l\n",x0+wx,y0);
     fprintf(psfile,"%.4g %.4g l\n",x0+wx,y0+wy);
     fprintf(psfile,"%.4g %.4g l\n",x0,y0+wy);
     fprintf(psfile,"c\n");
     fprintf(psfile,"f\n");
}

void PS_Fill_Rectangle(double x0, double y0, double wx, double wy)

{
     PS_Fill_Rectangle(PS_Current_File,x0,y0,wx,wy);
}

void PS_Normal_Line(FILE *psfile)
{
     fprintf(psfile,"[] 0 sd\n");
}

void PS_Normal_Line()
{
     PS_Normal_Line(PS_Current_File);
}

void PS_Dashed_Line(FILE *psfile)
{
     fprintf(psfile,"[3 2] 0 sd\n");
}

void PS_Dashed_Line()
{
     PS_Dashed_Line(PS_Current_File);
}

void PS_Set_Line_Width(FILE *psfile, double f)
{
     fprintf(psfile,"%.4g sl\n",f);
}

void PS_Set_Line_Width(double f)
{
     PS_Set_Line_Width(PS_Current_File,f);
}

void PS_Color(FILE *psfile, double red, double green, double blue)
{
     fprintf(psfile,"%.4g %.4g %.4g sr\n", red, green, blue);
}

void PS_Color(double red, double green, double blue)
{
     PS_Color(PS_Current_File,red,green,blue);
}

void PS_Arc(FILE *psfile, double cx0, double cy0, double R,
	    double a0, double a1)
{
     fprintf(psfile,"n\n");
     fprintf(psfile,"%.4g %.4g %.4g %.4g %.4g arc\n",cx0,cy0,R,a0,a1);
     fprintf(psfile,"s\n");
}

void PS_Arc(double cx0, double cy0, double R, double a0, double a1)
{
     PS_Arc(PS_Current_File,cx0,cy0,R,a0,a1);
}

// void PS_Curve(FILE *psfile, double x1, double y1, double x2, double y2,
// 	      double x3, double y3, double x4, double y4)
// {
//      fprintf(psfile,"n\n");
//      fprintf(psfile,"%.4g %.4g m\n",x1,y1);
//      fprintf(psfile,"%.4g %.4g %.4g %.4g %.4g %.4g curveto\n",
// 	     x2,y2,x3,y3,x4,y4);
//      fprintf(psfile,"s\n");
//}

// void PS_Curve(double x1, double y1, double x2, double y2,
// 	      double x3, double y3, double x4, double y4)
// {
//      PS_Curve(PS_Current_File,x1,y1,x2,y2,x3,y3,x4,y4);
// }

void PS_Polygon(FILE *psfile, const Vector &X, const Vector &Y)
{
     if (!X.N || !Y.N) return;
     fprintf(psfile,"n\n");
     fprintf(psfile,"%.4g %.4g m\n",X(1),Y(1));
     for (long i=2;i<=X.N;i++)
	  fprintf(psfile,"%.4g %.4g l\n",X(i),Y(i));
     fprintf(psfile,"s\n");
}

void PS_Polygon(const Vector &X, const Vector &Y)
{
     PS_Polygon(PS_Current_File,X,Y);
}

void PS_Fill_Polygon(FILE *psfile, const Vector &X, const Vector &Y)
{
     fprintf(psfile,"n\n");
     fprintf(psfile,"%.4g %.4g m\n",X(1),Y(1));
     for (long i=2;i<=X.N;i++)
	  fprintf(psfile,"%.4g %.4g l\n",X(i),Y(i));
     fprintf(psfile,"f\n");
}

void PS_Fill_Polygon(const Vector &X, const Vector &Y)
{
     PS_Fill_Polygon(PS_Current_File,X,Y);
}

const char *PS_Default_Font="Times-Roman";

void PS_Prepare_Font(FILE *psfile, const char *fontname, int size)
{
     fprintf(psfile,"/%s findfont\n",fontname);
     fprintf(psfile,"%d scalefont\n",size);
     fprintf(psfile,"setfont\n");
}

void PS_Prepare_Font(const char *fontname, int size)
{
     PS_Prepare_Font(PS_Current_File,fontname,size);
}

void PS_Text(FILE *psfile, double x0, double y0, const char *S)
{
     fprintf(psfile,"%.4g %.4g m\n",x0,y0);
     fprintf(psfile,"(%s) show\n",S);
}

void PS_Text(double x0, double y0, const char *S)
{
     PS_Text(PS_Current_File,x0,y0,S);
}

#endif


