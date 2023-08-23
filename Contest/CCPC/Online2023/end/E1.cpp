#include <bits/stdc++.h>
using namespace std;
#define int long long

map<char, pair<int, int>> dt;
string s;
int n;
set<pair<int, int>> q;
map<pair<int, int>, int> ob;

inline void dfs(int cur, int xx, int yy) {
    if (cur > n) {
        q.insert({xx, yy});
        return;
    }
    auto &[dx, dy] = dt[s[cur]];
    int nx = xx + dx, ny = yy + dy;
    if (ob[{nx, ny}] == 0) {
        ob[{nx, ny}] = 1;
        dfs(cur + 1, nx, ny);
        ob[{nx, ny}] = 0;

        ob[{nx, ny}] = 2;
        dfs(cur + 1, xx, yy);
        ob[{nx, ny}] = 0;
    } else if (ob[{nx, ny}] == 1) {
        dfs(cur + 1, nx, ny);
    } else if (ob[{nx, ny}] == 2) {
        dfs(cur + 1, xx, yy);
    }
}

signed main() {
    dt['L'] = {-1, 0};
    dt['R'] = {1, 0};
    dt['U'] = {0, 1};
    dt['D'] = {0, -1};
    ob[{0, 0}] = 1;
    cin >> n >> s;
    s = " " + s;
    dfs(1, 0, 0);
    cout << q.size() << '\n';
    for (auto &[x, y] : q) {
        cout << x << " " << y << endl;
    }
    return 0;
}