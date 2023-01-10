#include<stdio.h>
int main()
{
    int i,n,a,s=0,count=0;
    scanf("%d",&n);
    if(n==0)
    {
        printf("average = 0.0\ncount = 0\n");
        return 0;
    }
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        s+=a;
        if(a>=60)   
            count++;
    }
    printf("average = %.1lf\ncount = %d",(double)s/n,count);
    return 0;
}