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
vector<Edge> G; // 存储边目录

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
        // 一个匿名函数
        auto OK = [&]() {
            // 图染色数不是k，则方案不正确
            if (st.size() != k)
                return false;
            for (auto &[u, v] : G)
                if (color[u] == color[v]) // 存在两个相邻顶点具有同一种颜色，方案不正确
                    return false;
            return true;
        };
        puts(OK() ? "Yes" : "No");
    }
}