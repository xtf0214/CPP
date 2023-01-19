/**
 * @file    :   D
 * @author  :   Tanphoon
 * @date    :   2023/01/18 13:35
 * @version :   2023/01/18 13:35
 * @link    :   https://ac.nowcoder.com/acm/contest/46810/D
 */
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
#define print(v) for (int i = 0; i < v.size(); cout << v[i] << " \n"[++i == v.size()])
const int N = 1e6 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;

struct Node {
    vector<int> son;
    ll sum;
    int dep;
};
vector<Node> tr;
vector<int> energy;
vector<bool> vis;
int n;
void dfs(int u) {
    if (vis[u])
        return;
    vis[u] = true;
    for (int v : tr[u].son) {
        tr[v].dep = tr[u].dep + 1;
        dfs(v);
        tr[u].sum += tr[v].sum;
    }
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    tr.resize(n + 1);
    vis.resize(n + 1);
    energy.resize(n);
    for (int i = 2, f; i <= n; i++) {
        cin >> f;
        tr[f].son.push_back(i);
    }
    for (int i = 0; i < n; i++)
        cin >> energy[i];
    sort(energy.begin(), energy.end(), greater());
    dfs(1);
    vector<pii> ranks;
    for (int i = 1; i <= n; i++)
        ranks.push_back({tr[i].dep, i});
    sort(ranks.begin(), ranks.end(), greater());
    for (int i = 0; i < n; i++)
        tr[ranks[i].second].sum = energy[i];
    vis.assign(n + 1, false);
    dfs(1);
    ll ans = 0;
    for (int i = 1; i <= n; i++)
        ans += tr[i].sum;
    cout << ans << endl;
    return 0;
}
