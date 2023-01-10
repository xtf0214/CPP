// P1874 快速求和
// https://www.luogu.com.cn/problem/P1874
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string str;
    int t, n;
    cin >> str >> t;
    n = str.size();
    vector<vector<int>> sub(n + 1, vector<int>(n + 1));
    vector<vector<int>> f(n + 1, vector<int>(1e6 + 5, INF));
    f[0][0] = -1;
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            if (sub[i][j - 1] > t)
                sub[i][j] = INF;
            else
                sub[i][j] = sub[i][j - 1] * 10 + str[j - 1] - 48;
    for (int i = 1; i <= n; i++)
        for (int s = 0; s <= t; s++)
            for (int j = i - 1; j >= 0 && sub[j + 1][i] <= t; j--)
                if (s >= sub[j + 1][i])
                    f[i][s] = min(f[i][s], f[j][s - sub[j + 1][i]] + 1);
    cout << (f[n][t] < n ? f[n][t] : -1);
    return 0;
}