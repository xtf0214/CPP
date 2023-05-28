/**
 * @file    :   A 列车售货员难题
 * @author  :   therehello https://ac.nowcoder.com/acm/contest/view-submission?submissionId=62266630
 * @date    :   2023/05/26 00:47
 * @version :   2023/05/26 00:47
 * @link    :   https://ac.nowcoder.com/acm/contest/58860/A
 */
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> p(m + 1);
    for (int i = 1, t; i <= n; i++) {
        cin >> t;
        for (int j = 1, x; j <= t; j++) {
            cin >> x;
            p[x].emplace_back(i);
        }
    }
    for (int i = 1; i <= m; i++)
        reverse(p[i].begin(), p[i].end());
    // p[i]: 物品i在哪些车厢里，降序
    unordered_set<bitset<100>> st;
    for (int i = 1; i <= n; i++) {
        bitset<100> cur;
        vector<pair<int, int>> pos;
        for (int j = 1; j <= m; j++) {
            while (!p[j].empty() && p[j].back() < i)
                p[j].pop_back();
            if (!p[j].empty())
                pos.emplace_back(p[j].back(), j); // 从i开始计算，j物品最小出现的车厢编号
        }
        sort(pos.begin(), pos.end());
        for (int j = 0; j < pos.size(); j++) {
            auto [id, v] = pos[j];
            cur[v - 1] = 1;
            // 每向后走一个车厢，都记录一下从i到当前车厢j所产生的物品序列
            if (j == pos.size() - 1 || pos[j].first != pos[j + 1].first)
                st.insert(cur);
        }
    }

    cout << st.size() << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt = 1;
    // cin >> tt;
    while (tt--)
        solve();

    return 0;
}