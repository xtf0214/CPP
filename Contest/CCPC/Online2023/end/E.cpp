#include <bits/stdc++.h>
using namespace std;
#define int long long

map<char, pair<int, int>> dt;
string s;
int n;
set<pair<int, int>> q;
map<pair<int, int>, int> mp;
map<pair<int, int>, int> ob;

inline void dfs(int cur, int xx, int yy) {
    if (cur > n) {
        q.insert({xx, yy});
        return;
    }
    int nx, ny;
    if (s[cur] == 'U') {
        nx = xx, ny = yy + 1;
    } else if (s[cur] == 'R') {
        nx = xx + 1, ny = yy;
    } else if (s[cur] == 'D') {
        nx = xx, ny = yy - 1;
    } else if (s[cur] == 'L') {
        nx = xx - 1, ny = yy;
    }
    if (nx == 0 && ny == 0)
        dfs(cur + 1, nx, ny);
    else {
        if (mp[{nx, ny}] == 1) {
            if (ob[{nx, ny}] == 1)
                dfs(cur + 1, nx, ny);
            else
                dfs(cur + 1, xx, yy);
        } else {
            mp[{nx, ny}] = 1;
            ob[{nx, ny}] = 1;
            dfs(cur + 1, nx, ny);
            ob[{nx, ny}] = 0;

            ob[{nx, ny}] = 2;
            dfs(cur + 1, xx, yy);
            ob[{nx, ny}] = 0;
            mp[{nx, ny}] = 0;
        }
    }
}

signed main() {
    cin >> n >> s;
    s = " " + s;
    dfs(1, 0, 0);
    cout << q.size() << '\n';
    for (auto &[x, y] : q) {
        cout << x << " " << y << endl;
    }
    return 0;
}