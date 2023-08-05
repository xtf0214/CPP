#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int N = 50, INF = 0x3f3f3f3f, mod = 1e9 + 7;
int main()
{
    ios::sync_with_stdio(0);
    int m;
    int st[N][N]{0};
    pii pos[N * N];
    cin >> m;
    pos[1] = {0, (m - 1) / 2};
    st[0][(m - 1) / 2] = 1;
    for (int i = 2; i <= m * m; i++)
    {
        auto &[y, x] = pos[i - 1];
        if (y == 0 && x != m - 1)
            pos[i] = {m - 1, x + 1};
        else if (y != 0 && x == m - 1)
            pos[i] = {y - 1, 0};
        else if (y == 0 && x == m - 1)
            pos[i] = {y + 1, x};
        else if (y != 0 && x != m - 1)
        {
            if (st[y - 1][x + 1] == 0)
                pos[i] = {y - 1, x + 1};
            else
                pos[i] = {y + 1, x};
        }
        st[pos[i].fi][pos[i].se] = i;
    }
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            cout << st[i][j] << " \n"[j == m - 1];
    return 0;
}