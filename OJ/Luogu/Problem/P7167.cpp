#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#define print(v) for (int i = 0; i < v.size(); cout << v[i] << (char[2][2]){" ", "\n"}[i == v.size() - 1], ++i)
const int N = 1e6 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;
const int vec[4][2]{{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

void solve()
{
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    stack<int> s;
    cin >> n >> m;
    vi d(n), c(n), next(n);
    for (int i = 0; i < n; i++)
        cin >> d[i] >> c[i];
    d.push_back(INF), c.push_back(INF);
    for (int i = 0; i <= n; i++)
    {
        while (!s.empty() && d[s.top()] < d[i])
            next[s.top()] = i, s.pop();
        s.push(i);
    }
    print(next);
    return 0;
}