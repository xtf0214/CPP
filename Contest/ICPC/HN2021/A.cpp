#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, h, w;
    cin >> n >> m;
    vector G(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> G[i][j];
    cin >> h >> w;
    bool ok = false;
    for (int y1 = 1, y2 = y1 + h - 1; y2 <= n; y1++, y2++)
        for (int x1 = 1, x2 = x1 + w - 1; x2 <= m; x1++, x2++)
            if (G[y1][x1] == G[y1][x2] && G[y1][x2] == G[y2][x1] && G[y2][x1] == G[y2][x2])
                ok = true;
    puts(ok ? "YES" : "NO");
}