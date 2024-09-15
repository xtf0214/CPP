/**
 * @file    :   E
 * @author  :   Tanphoon
 * @date    :   2024/05/29 02:16
 * @version :   2024/05/29 02:16
 * @link    :   https://codeforces.com/gym/105184/problem/E
 */
#include <bits/stdc++.h>
using namespace std;
struct Point {
    int x, y;
};
double dist(Point a, Point b) { return hypot(a.x - b.x, a.y - b.y); }
int main() {
    int n, m, k, b, e;
    cin >> n >> m >> k >> b >> e;
    vector<Point> pos(k + 4);
    for (int i = 0; i < k + 4; i++)
        cin >> pos[i].x >> pos[i].y;
    int s = max((n + b - 1) / b, (m + e - 1) / e);
    vector<vector<double>> d(k, vector<double>(4, 1e8));
    // 学生 u 去 cnt 个食堂的最短路径
    auto dfs = [&](auto &&dfs, int u, int cnt, int cur, int pre, int S, double now) {
        if (now >= d[u][cnt])
            return;
        if (cur == cnt) {
            d[u][cnt] = min(d[u][cnt], now + dist(pos[3], pos[pre]));
            return;
        }
        for (int i = 0; i < 3; i++) {
            if (!(S >> i & 1)) {
                if (pre == -1)
                    dfs(dfs, u, cnt, cur + 1, i, S | 1 << i, now + dist(pos[u + 4], pos[i]));
                else
                    dfs(dfs, u, cnt, cur + 1, i, S | 1 << i, now + dist(pos[pre], pos[i]));
            }
        }
    };
    for (int u = 0; u < k; u++) {
        d[u][0] = 0;
        vector<int> st(3);
        for (int i = 1; i <= 3; i++)
            dfs(dfs, u, i, 0, -1, 0, 0);
    }
    vector<double> f(s + 1, 1e9);
    f[0] = 0;
    for (int i = 0; i < k; i++) {          // 第i个人
        for (int j = s; j >= 0; j--) {     // 背包容量
            for (int k = 1; k <= 3; k++) { // 去k个餐厅
                if (j >= k) {
                    f[j] = min(f[j], f[j - k] + d[i][k]);
                }
            }
        }
    }
    printf("%.10lf", f[s]);
}
