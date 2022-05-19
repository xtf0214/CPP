#include<stdio.h>
#include<math.h>
int main()
{
	double x,t,s=0;
	int i;
	scanf("%lf",&x);
	t=x;
	s+=t;
	for(i=2;;i++)
	{
		t=-t*x*x/(2*i-1)/(2*i-2);
		if(fabs(t)<0.00001)
		{
			s+=t;
			i++;
			break; 
		}
		s+=t;
	}
	printf("%lf %d",s,i-2);
	return 0;
} 
