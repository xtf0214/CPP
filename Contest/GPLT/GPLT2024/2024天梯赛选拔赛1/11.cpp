/**
 * @file    :   愿天下有情人都是失散多年的兄妹
 * @author  :   Tanphoon
 * @date    :   2023/12/25 10:14
 * @version :   2023/12/25 10:14
 */
#include <bits/stdc++.h>
using namespace std;

struct P {
    char sex;
    int f = -1, m = -1;
} p[100010];
map<int, int> mp;
bool flag;
void dfs(int u, int dep) {
    if (dep > 5 || u == -1)
        return;
    mp[u]++;
    if (mp[u] >= 2)
        flag = 0;
    dfs(p[u].f, dep + 1);
    dfs(p[u].m, dep + 1);
}
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        cin >> p[x].sex >> p[x].f >> p[x].m;
        if (p[x].f != -1)
            p[p[x].f].sex = 'M';
        if (p[x].m != -1)
            p[p[x].m].sex = 'F';
    }
    int m;
    cin >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;
        if (p[x].sex == p[y].sex) {
            cout << "Never Mind\n";
        } else {
            flag = 1;
            mp.clear();
            dfs(x, 1);
            dfs(y, 1);
            if (flag)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }
}