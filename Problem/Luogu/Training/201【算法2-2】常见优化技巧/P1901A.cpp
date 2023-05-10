// P1901 发射站
// https://www.luogu.com.cn/problem/P1901
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;
const int INF = 0x3f3f3f3f;

int n;
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    vi a(n + 2), v(n + 2);
    vll res(n + 2);
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> v[i];
    a[0] = a[n + 1] = INF;
    stack<int> s;
    for (int i = 0; i <= n + 1; i++)
    {
        while (!s.empty() && a[s.top()] < a[i]) // 单调递减栈
        {
            res[i] += v[s.top()]; // 向右发射
            s.pop();
        }
        if (!s.empty())
            res[s.top()] += v[i]; // 向左发射
        s.push(i);
    }
    cout << *max_element(res.begin() + 1, res.end() - 1);
    return 0;
}