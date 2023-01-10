#include<stdio.h>
void Swap(int *x,int *y)
{
    int t=*x;
    *x=*y;
    *y=t;
}
int main()
{
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    if(a>b) Swap(&a,&b);
    if(a>c) Swap(&a,&c);
    if(b>c) Swap(&b,&c);
    printf("%d->%d->%d",a,b,c);
    return 0; 
}
