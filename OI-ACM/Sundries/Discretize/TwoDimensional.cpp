/**
 * @file    :   TwoDimensional
 * @author  :   Tanphoon
 * @date    :   2022/10/25 01:09
 * @version :   2023/01/25 23:25
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int vec[4][2]{{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

int n, w, h;
ll ans;
vector<pii> ax, ay;
vector<vector<int>> f;
// 将a数组离散化，逆映射保存在d中。d[a']->a
int compress(vector<pii> &a, int n) {
    vector<int> d;
    for (auto &[l, r] : a)
        for (int b = -1; b <= 1; b++) { // 相邻的两个分隔
            int t1 = l + b, t2 = r + b;
            if (1 <= t1 && t1 <= n)
                d.push_back(t1);
            if (1 <= t2 && t2 <= n)
                d.push_back(t2);
        }
    sort(d.begin(), d.end());
    d.erase(unique(d.begin(), d.end()), d.end());
    auto get = [&d](int x) { return lower_bound(d.begin(), d.end(), x) - d.begin(); };
    for (auto &[l, r] : a)
        l = get(l), r = get(r);
    return d.size();
}
void bfs(int y, int x) {
    queue<pii> q;
    q.push({y, x});
    while (!q.empty()) {
        auto [cy, cx] = q.front();
        q.pop();
        f[cy][cx] = 1;
        for (auto &[ty, tx] : vec) {
            int ny = cy + ty, nx = cx + tx;
            if (ny < 0 || ny >= h || nx < 0 || nx >= w || f[ny][nx])
                continue;
            q.push({ny, nx});
        }
    }
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> h >> w;
    for (int i = 0, x1, x2, y1, y2; i < n; i++) {
        cin >> x1 >> x2 >> y1 >> y2;
        ax.push_back({x1, x2});
        ay.push_back({y1, y2});
    }
    h = compress(ay, h);
    w = compress(ax, w);
    f.resize(h, vector<int>(w));
    // 离散后修改
    for (int i = 0; i < n; i++)
        for (int j = ay[i].first; j <= ay[i].second; j++)
            for (int k = ax[i].first; k <= ax[i].second; k++)
                f[j][k] = 1;
    // for (int i = 0; i < h; i++, cout << endl)
    //     for (int j = 0; j < w; j++)
    //         cout << (f[i][j] ? "[]" : "  ");
    // cout << endl;
    // 逆映射到离散前
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) {
            if (f[i][j])
                continue;
            bfs(i, j);
            ans++;
        }
    cout << ans << endl;
    return 0;
}
/*
5 10 10
1 6 4 4
1 10 8 8
4 4 1 10
9 9 1 5
10 10 6 10 */