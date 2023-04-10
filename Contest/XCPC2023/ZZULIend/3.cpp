#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
string str;
int n, mx = 0, a[N], b[N];
vector<int> G[N];
vector<string> ans;

inline void dfs(int u, int cur) {
    if (cur > 9)
        return;
    str += b[u] + '0';
    for (int v : G[u])
        dfs(v, cur + 1);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        mx = max(mx, b[i]);
    }
    if (mx == 0) {
        puts("0");
        return 0;
    }
    for (int i = 1; i <= n; i++)
        G[i].push_back(a[i]);
    for (int i = 1; i <= n; i++)
        if (b[i] == mx) {
            str.clear();
            dfs(i, 1);
            ans.push_back(str);
        }
    sort(ans.begin(), ans.end());
    cout << ans.back() << endl;
    return 0;
}