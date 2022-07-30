#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int main()
{
    int a[MAXN]{0}, n;
    cin >> n;
    for (int i = 0; i < n;i++)
        cin >> a[i];
    sort(a, a + n);
    long long top = 0;
    for (int i = 0; i < n;i++)
        if(a[i]<=top+1)
            top += a[i];
        else
            break;
    cout << top + 1;
    return 0;
}
/* 
[1,top]={0,1,2,...,top}
{0,1,2,3}+5={5-1,5+0,5+1,5+2,5+3} error:不存在-1
{0,1,2,3}+4={4+0,4+1,4+2,4+3}
{0,1,2,3}+3={3+1,3+2,3+3}

{0,1,2,...,top}+i={
                i+(top+1-i)+0,(top+1)
                i+(top+1-i)+1,(top+2)
                ...,
                i+(top+1-i)+i-2,(top+i-1)
                i+(top+1-i)+i-1,(top+i)
                }
于是 top+1-i>=0
 */
