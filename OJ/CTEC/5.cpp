#include<stdio.h>
int Prime(int x)
{
	for(int i=2;i*i<=x;i++)
		if(x%i==0)
			return 0;
	return 1;
}
int main()
{
	int A[10001]={0};
	int cnt=0,n,s=0;
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
		if(Prime(i))
			A[i]=1,cnt++;
	if(cnt<10)
	{
		for(int i=2;i<=n;i++)
			if(A[i]==1)
				s+=i;
		printf("sum=%d",s);
	}
	else if(cnt>=10)
	{
		for(int i=n,j=0;j<10;i--)
			if(A[i]==1)
				s+=i,j++;
		printf("sum=%d",s);
	}
	return 0;
}
