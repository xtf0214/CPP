// P1824 进击的奶牛
// https://www.luogu.com.cn/problem/P1824
#include <bits/stdc++.h>
using namespace std;
template <typename T>
using vT = vector<T>;
#define all(v) v.begin(), v.end()
const int N = 1e6 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;

int n, c;
vT<int> a;
bool check(int d)
{
    int k = 0, st = -INF;
    for (int i = 0; i < n; i++)
        if (a[i] - st >= d)
            st = a[i], k++;
    return k >= c;
}
signed main()
{
    cin >> n >> c;
    a = vT<int>(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(all(a));
    int l = 0, r = INF, mid;
    while (r - l > 1)
        if (check(mid = (l + r) / 2))
            l = mid;
        else
            r = mid;
    cout << l << endl;
    return 0;
}