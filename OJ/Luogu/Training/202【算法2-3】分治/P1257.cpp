#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define x first
#define y second
#define all(v) v.begin(), v.end()
const int N = 1e6 + 5, INF = 0x3f3f3f3f;

int n;
vector<pii> p;
double dist(pii &a, pii &b) { return hypot(a.x - b.x, a.y - b.y); }
double merge(int l, int r)
{
    double dis = INF;
    if (l == r)
        return dis;
    if (r - l == 1)
        return dist(p[l], p[r]);
    int mid = (l + r) >> 1;
    double dl = merge(l, mid);
    double dr = merge(mid + 1, r);
    dis = min(dl, dr);
    // 宽度为dis的带域内的点保存到tmp
    vector<pii> tmp;
    for (auto &i : p)
        if (abs(i.x - p[mid].x) <= dis)
            tmp.push_back(i);
    // 按坐标从上到下排序
    sort(all(tmp), [](pii &a, pii &b)
         { return a.y < b.y; });
    // 计算每一组上下两点的距离
    for (int i = 0; i < tmp.size(); i++)
        for (int j = i + 1; j < tmp.size() && tmp[j].y - tmp[i].y < dis; j++)
            dis = min(dis, dist(tmp[i], tmp[j]));
    return dis;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    p = vector<pii>(n);
    for (int i = 0; i < n; i++)
        cin >> p[i].x >> p[i].y;
    sort(all((p)));
    double res = merge(0, n - 1);
    printf("%.4lf\n", res);
    return 0;
}