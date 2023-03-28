#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;

void solve2()
{
    int week = 5;
    int cnt = 0;
    const int Month[13]{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int i = 1; i <= 12; i++)
        for (int j = 1; j <= Month[i]; j++)
        {
            week = (week + 1) % 7;
            if (week == 6 || j == 1 || j == 11 | j == 21 || j == 31)
                cnt++;
        }
    cout << cnt << endl;
}
void solve3()
{
    double sum = 0;
    for (int i = 1;; i++)
    {
        sum += 1.0 / i;
        if (sum > 12)
            return void(cout << i);
    }
    // 91380
}
void solve4()
{
    int ans = 0;
    char g[30][61];
    for (int i = 0; i < 30; i++)
        cin >> g[i];
    for (int i = 1; i <= 28; i++)
        for (int j = 1; j <= 58; j++)
            if (g[i][j] < g[i - 1][j] && g[i][j] < g[i + 1][j] && g[i][j] < g[i][j - 1] && g[i][j] < g[i][j + 1])
                ans++;
    cout << ans;
}
void solve5()
{
    int a[101][101]{0};
    static int sum[101][101];
    for (int i = 1; i <= 100; i++)
        for (int j = 1; j <= 100; j++)
        {
            if (i == 1 && j == 1)
                a[i][j] = 1;
            else if (j == 1)
                a[i][j] = a[i - 1][j] + 1;
            else
                a[i][j] = a[i][j - 1] + 2;
        }
    for (int i = 1; i <= 100; i++)
        for (int j = 1; j <= 100; j++)
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
    auto getSum = [](int y1, int x1, int y2, int x2)
    { return sum[y2][x2] - sum[y2][x1 - 1] - sum[y1 - 1][x2] + sum[y1 - 1][x1 - 1]; };
    int x, y, minn = INF;
    for (int y1 = 1; y1 <= 100; y1++)
        for (int x1 = 1; x1 <= 100; x1++)
            for (int y2 = y1; y2 <= 100; y2++)
                for (int x2 = x1; x2 <= 100; x2++)
                {
                    if (x2 == x1 && y2 == y1)
                        continue;
                    int res = getSum(y1, x1, y2, x2);
                    if (res > 2022)
                        break;
                    if (res == 2022)
                    {
                        cout << y1 << " " << x1 << " " << y2 << " " << x2 << " " << (y2 - y1 + 1) * (x2 - x1 + 1) << endl;
                        minn = min(minn, (y2 - y1 + 1) * (x2 - x1 + 1));
                    }
                }
    cout << minn;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve5();
    return 0;
}