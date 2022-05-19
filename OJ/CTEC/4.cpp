#include<stdio.h>
int main()
{
	int x,y,a,b,c,d;
	scanf("%d %d",&x,&y);
	a=x/100%10;
	b=x/10%10;
	c=y/1000%10;
	d=y/100%10;
	printf("%d",a+b-c*d);
	return 0;
}
