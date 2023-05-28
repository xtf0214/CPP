#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 1e6 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;
int read(int x = 0) { return cin >> x, x; }

int n;
int a[N], s[N], dep[N], fa[N];
vector<int> G[N], st;

void dfs(int u) {
    for (int v : G[u]) {
        if (v == fa[u])
            continue;
        fa[v] = u;
        dep[v] = dep[u] + 1;
        dfs(v);
    }
}

int lca(int x, int y) {
    if (dep[x] < dep[y])
        swap(x, y);
    while (dep[x] > dep[y])
        x = fa[x];
    while (x != y)
        x = fa[x], y = fa[y];
    return x;
}

void work(int d) {
    if (d == n + 1) {
        if (st.size() == 0)
            return;
        int t = accumulate(st.begin(), st.end(), st[0], lca);
        // if (st.size() & 1)
        //     s[t]++;
        // else
        //     s[t]--;
        // print(st);
        // dbgx(t) << endl << endl;
        s[t]++;
        return;
    }
    st.push_back(d);
    work(d + 1);
    st.pop_back();
    work(d + 1);
}
int main() {
    n = read();
    for (int i = 2; i <= n; i++) {
        int v = read();
        G[v].push_back(i);
        G[i].push_back(v);
    }
    dfs(1);
    work(1);
    for (int i = 1; i <= n; i++)
        cout << s[i] << ' ';
}