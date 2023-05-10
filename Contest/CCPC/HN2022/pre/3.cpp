#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vii = vector<vi>;
int n, m, h;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> h;
    vi f(n), l(m);
    vii H(n, vi(m, -1));
    for (int i = 0; i < m; i++)
        cin >> l[i];
    for (int i = 0; i < n; i++)
        cin >> f[i];
    for (int i = 0; i < n; i++)
        for (int j = 0, t; j < m; j++)
        {
            cin >> t;
            H[i][j] = t ? min(f[i], l[j]) : 0;
        }
    for (int i = 0; i < n; i++)
        for (int j = 0, t; j < m; j++)
            cout << H[i][j] << " \n"[j == m - 1];
}