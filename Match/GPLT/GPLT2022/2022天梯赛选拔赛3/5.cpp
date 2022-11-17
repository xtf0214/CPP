// 7-5 御膳房
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, a[105] = {0}, maxm = 0;
    cin >> n;
    for (int i = 0, k; i < n; i++)
    {
        cin >> k;
        a[k]++;
        maxm = max(maxm, a[k]);
    }
    if (maxm <= n / 2 + 1) //重复元素不大于总数的1/2+1就可以插空
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}