// P1115 最大子段和
// https://www.luogu.com.cn/problem/P1115
#include <iostream>
using namespace std;
const int N = 2e5 + 5, INF = 0x3f3f3f3f;
int main()
{
    int n, a, f = 0, ans = -INF;
    cin >> n;
    for (int i = 0; i < n;i++)
    {
        cin >> a;
        f = max(f + a, a);
        ans = max(f, ans);
    }
    cout << ans;
    return 0;
}