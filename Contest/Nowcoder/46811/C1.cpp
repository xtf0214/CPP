/**
 * @file    :   C1
 * @author  :   Tanphoon
 * @date    :   2023/01/20 15:19
 * @version :   2023/01/20 15:19
 * @link    :   https://ac.nowcoder.com/acm/contest/46811/C
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define print(v) for (int i = 0; i < v.size(); cout << v[i] << " \n"[++i == v.size()])
const int N = 1e6 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;

int n, cnt;
vector<int> pos;
vector<int> vis;
void dfs(int k) {
    if (k == n + 1) {
        cnt++;
        for (int i = 1; i <= n; i++)
            cout << pos[i] << " ";
        cout << endl;
        exit(0);
    }
    int a[]{k - 3, k - 2, k + 2, k + 3};
    for (int i : a)
        if (1 <= i && i <= n && !vis[i]) {
            vis[i] = true;
            pos[i] = k;
            dfs(k + 1);
            vis[i] = false;
        }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    cnt = 0;
    vis.assign(n + 1, 0);
    pos.assign(n + 1, 0);
    dfs(1);
    if (!cnt)
        cout << -1 << endl;
    return 0;
}