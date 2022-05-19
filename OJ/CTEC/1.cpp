#include<stdio.h>

int main()
{
	int x,y;
	scanf("%d",&x);
	if(x<10)
		y=-x;
	else if(x==10)
		y=31;
	else if(x>10 && x<=100)
		y=3*x-7;
	else if(x>100)
		y=x*x-5*x+1;
	printf("%d",y);
	return 0;
} 
