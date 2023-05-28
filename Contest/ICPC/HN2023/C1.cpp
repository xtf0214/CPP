#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define print(v) for (auto it = v.begin(); it != v.end(); cout << *it << " \n"[next(it++) == v.end()])
#define dbgx(x) cerr << #x << " : " << x << "; "
#define dbgai(a, i) cerr << #a << "[" << i << "] : " << a[i] << "; "
const int N = 1e6 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;
int read(int x = 0) { return cin >> x, x; }
int pow2(int x) { return 1 << x; }

int n;
vector<int> G[N];
int a[N];
int s[N];
int res[N];
void dfs(int u) {
    for (int v : G[u]) {
        dfs(v);
        s[u] += s[v] + 1;
        res[u] -= pow2(s[v] + 1) - 1;
    }
    res[u] += pow2(s[u] + 1) - 1;
}
int main() {
    n = read();
    for (int i = 2; i <= n; i++) {
        G[read()].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        a[i] = read();
    }
    G[0].push_back(1);
    dfs(1);
    for (int i = 1; i <= n; i++)
        dbgai(res, i) << endl;
}
