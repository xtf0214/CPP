// P1638 逛画展
// https://www.luogu.com.cn/problem/P1638
#include <iostream>
using namespace std;
const int N = 1e6 + 5,INF=0x3f3f3f3f;
int n, m, ansl, ansr;
int main()
{
    cin >> n >> m;
    int a[N], sum[N]{0};
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int l = 1, r = 1, num = 0, ans = INF;
    while (l <= r && r <= n + 1)
    {
        if (num < m)
        {
            r++;
            sum[a[r - 1]]++;
            if (sum[a[r - 1]] == 1)
                num++;
        }
        else
        {
            if (ans > r - l)
            {
                ans = r - l;
                ansl = l;
                ansr = r - 1;
            }
            sum[a[l]]--;
            if (sum[a[l]] == 0)
                num--;
            l++;
        }
    }
    cout << ansl << " " << ansr;
    return 0;
}