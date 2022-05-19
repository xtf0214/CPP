#include<stdio.h>

int main()
{
	int M[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	int y,m;
	scanf("%d %d",&y,&m);
	if(y<2001||y>2100||m<1||m>12)
	{
		printf("error");
		return 0;
	}
	M[2]+=(y%400==0||y%4==0&&y%100!=0)?1:0;
	printf("%d",M[m]);
	return 0;
} 
