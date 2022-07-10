#include<cstdio>
using namespace std;
int a[10001]; 
int main()
{
    int Test;
    scanf("%d",&Test);
    while(Test--)
    {
        int ans=0,N;
        scanf("%d",&N);
        for(int i=1;i<=N;i++) scanf("%d",&a[i]);
        for(int i=1;i<=N;i++) ans=ans^a[i];
        ans==0?printf("No\n"):printf("Yes\n");
    }
    return 0;
}
