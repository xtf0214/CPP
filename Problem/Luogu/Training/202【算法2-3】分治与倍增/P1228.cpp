// P1228 地毯填补问题
// https://www.luogu.com.cn/problem/P1228
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
#define x first
#define y second

vvi Map;
vector<pair<pii, int>> ans;
void dfs(int x0, int y0, int k, pii Q)
{
    int x1 = x0, x2 = x0 + (1 << (k - 1));
    int y1 = y0, y2 = y0 + (1 << (k - 1));
    pii A{x2 - 1, y2 - 1}, B{x2, y2 - 1}, C{x2 - 1, y2}, D{x2, y2}; // 中心四点
    if (k == 0)
        return;
    if (x1 <= Q.x && Q.x < x2 && y1 <= Q.y && Q.y < y2) // 左上角区域
    {
        Map[B.x][B.y] = Map[C.x][C.y] = Map[D.x][D.y] = 1;
        ans.push_back({{D.x, D.y}, 1});
        dfs(x1, y1, k - 1, Q);
        dfs(x2, y1, k - 1, B);
        dfs(x1, y2, k - 1, C);
        dfs(x2, y2, k - 1, D);
    }
    else if (x2 <= Q.x && y1 <= Q.y && Q.y < y2) // 右上角区域
    {
        Map[A.x][A.y] = Map[C.x][C.y] = Map[D.x][D.y] = 2;
        ans.push_back({{C.x, C.y}, 2});
        dfs(x1, y1, k - 1, A);
        dfs(x2, y1, k - 1, Q);
        dfs(x1, y2, k - 1, C);
        dfs(x2, y2, k - 1, D);
    }
    else if (x1 <= Q.x && Q.x < x2 && y2 <= Q.y) // 左下角区域
    {
        Map[A.x][A.y] = Map[B.x][B.y] = Map[D.x][D.y] = 3;
        ans.push_back({{B.x, B.y}, 3});
        dfs(x1, y1, k - 1, A);
        dfs(x2, y1, k - 1, B);
        dfs(x1, y2, k - 1, Q);
        dfs(x2, y2, k - 1, D);
    }
    else // 右下角区域
    {
        Map[A.x][A.y] = Map[B.x][B.y] = Map[C.x][C.y] = 4;
        ans.push_back({{A.x, A.y}, 4});
        dfs(x1, y1, k - 1, A);
        dfs(x2, y1, k - 1, B);
        dfs(x1, y2, k - 1, C);
        dfs(x2, y2, k - 1, Q);
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int k, x0, y0;
    cin >> k >> y0 >> x0;
    Map = vvi((1 << k) + 1, vi((1 << k) + 1, 0));
    dfs(1, 1, k, {x0, y0});
    // for (int i = 1; i < Map.size(); i++, cout << endl)
    //     for (int j = 1; j < Map.size(); j++)
    //         cout << Map[i][j] << " ";
    // cout << endl;
    for (auto &i : ans)
        cout << i.first.y << " " << i.first.x << " " << i.second << endl;
    return 0;
}