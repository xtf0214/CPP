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
int n, cnt;
vector<int> pos;
vector<int> vis;
vector<int> del{-3, -2, 2, 3};
void dfs(int k) {
    if (k == n + 1) {
        cnt++;
        for (int i = 1; i <= n; i++)
            cout << pos[i] << " ";
        // cout << n;
        exit(0);
    }
    for (int i = 0; i < 4; i++)
        if (int x = k + del[i]; 1 <= x && x <= n && !vis[x]) {
    // for (int x : {k - 3, k - 2, k + 2, k + 3})
    //     if (1 <= x && x <= n && !vis[x]) {
            vis[x] = true;
            pos[x] = k;
            dfs(k + 1);
            vis[x] = false;
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