#include<stdio.h>
#include<math.h>
double s(double a,double b,double c)
{
	double d=(a+b+c)/2;
	return sqrt(d*(d-a)*(d-b)*(d-c));
}
int main()
{
	double x1,y1,x2,y2,x3,y3,x4,y4;
	double d1,d2,d3,d4,d5;
	scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
	d1=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	d2=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
	d3=sqrt((x3-x4)*(x3-x4)+(y3-y4)*(y3-y4));
	d4=sqrt((x4-x1)*(x4-x1)+(y4-y1)*(y4-y1));
	d5=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
	printf("%.6lf",s(d1,d2,d5)+s(d3,d4,d5));
	return 0;
}
