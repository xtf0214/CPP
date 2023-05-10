// P2947 [USACO09MAR]Look Up S
// https://www.luogu.com.cn/problem/P2947
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#define lowbit(x) x &(-x)
#define print(v) for (int i = 0; i < v.size(); cout << v[i] << " \n"[i++ == v.size() - 1])
const int N = 1e6 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;
const int vec[4][2]{{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

int n;
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    vi a(n), next(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    a.push_back(INF);
    stack<int> s;
    for (int i = 0; i < n + 1; i++)
    {
        while (!s.empty() && a[s.top()] < a[i]) // 单调递减栈
        {
            next[s.top()] = (a[i] == INF ? 0 : i + 1);
            s.pop();
        }
        s.push(i);
    }
    for (int i = 0; i < n; i++)
        cout << next[i] << endl;
    return 0;
}