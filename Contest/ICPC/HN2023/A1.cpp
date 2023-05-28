#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<__int128> bit(101);
    bit[0] = 1;
    for (int i = 1; i <= 100; i++)
        bit[i] = bit[i - 1] * 2;
    vector<vector<int>> p(m + 1);  // 物品i在哪些车厢里
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        for (int j = 1; j <= t; j++) {
            int x;
            cin >> x;
            p[x].emplace_back(i);
        }
    }
    for (int i = 1; i <= m; i++) {
        reverse(p[i].begin(), p[i].end());
    }

    set<__int128> st;
    for (int i = 1; i <= n; i++) {
        __int128 cur = 0;
        vector<pair<int, int>> pos;
        for (int j = 1; j <= m; j++) {
            while (p[j].size() && p[j].back() < i)
                p[j].pop_back();
            if (p[j].size())
                pos.emplace_back(p[j].back(), j);
        }
        sort(pos.begin(), pos.end());
        for (int j = 0; j < pos.size(); j++) {
            auto [id, v] = pos[j];
            cur += bit[v];
            if (j == pos.size() - 1 || pos[j].first != pos[j + 1].first)
                st.emplace(cur);
        }
    }

    cout << st.size() << '\n';
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int tt = 1;
    // cin >> tt;
    while (tt--)
        solve();

    return 0;
}