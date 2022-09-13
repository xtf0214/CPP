#include <stdio.h>
#define MAX 10000 + 5
int main()
{
    int x,cnt=0;
    scanf("%d", &x);
    while(x!=1)
    {
        if(x%2==0)
            x /= 2, cnt++;
        else
            x = x * 3 + 1, cnt++;
    }
    printf("%d", cnt);
    return 0;
}