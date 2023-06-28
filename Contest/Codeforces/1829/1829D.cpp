#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int n, m;

bool dfs(int s) {
    // cerr << s << ' ';
    if (s == m)
        return true;
    if (s % 3 != 0)
        return false;
    return dfs(s / 3) || dfs(s / 3 * 2); 
}

void solve() {
    cin >> n >> m;
    puts(dfs(n) ? "YES" : "NO");
    // cerr << '\n';
}

int main() {
    // freopen("D.in", "r", stdin);

    cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) 
        solve();
}