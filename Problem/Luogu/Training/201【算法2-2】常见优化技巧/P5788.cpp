// P5788 【模板】单调栈
// https://www.luogu.com.cn/problem/P5788
#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
const int N = 1e6 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vi a(n + 1), next(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    a.push_back(INF);
    stack<int> s;
    for (int i = 1; i <= n + 1; i++)
    {
        while (!s.empty() && a[s.top()] < a[i])
            next[s.top()] = i, s.pop();
        s.push(i);
    }
    for (int i = 1; i <= n; i++)
    {
        if (next[i] == n + 1)
            cout << 0 << " ";
        else
            cout << next[i] << " ";
    }
    return 0;
}