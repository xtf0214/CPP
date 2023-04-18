/**
 * @file    :   7-23 图着色问题
 * @author  :   Tanphoon
 * @date    :   2023/04/17 23:55
 * @version :   2023/04/17 23:55
 * @link    :
 */
#include <bits/stdc++.h>
using namespace std;

using Edge = pair<int, int>;
int n, m, k, T;
vector<Edge> G;

int main() {
    cin >> n >> m >> k;
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        G.push_back({u, v});
    }
    cin >> T;
    while (T--) {
        vector<int> color(n + 1);
        set<int> st;
        for (int i = 1; i <= n; i++) {
            cin >> color[i];
            st.insert(color[i]);
        }
        auto OK = [&]() {
            if (st.size() != k)
                return false;
            for (auto &[u, v] : G)
                if (color[u] == color[v])
                    return false;
            return true;
        };
        puts(OK() ? "Yes" : "No");
    }
}