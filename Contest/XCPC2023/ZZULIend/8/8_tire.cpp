// 102020 计科21——全局最优解队(司传钊\张青华\韩子昂)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

constexpr int mxn = 1e6 + 100;
struct Trie {
    int nxt[mxn][26], exist[mxn];
    int cnt = 0;
    void clear() {
        cnt = 0;
        memset(nxt[0], 0, sizeof(nxt[0]));
        memset(exist, 0, sizeof(exist));
    }
    void insert(string s) {
        int u = 0;
        for (char ch : s) {
            ch -= 'a';
            if (!nxt[u][ch])
                nxt[u][ch] = ++cnt;
            u = nxt[u][ch];
        }
        ++exist[u];
    }
    int query(string s) {
        int u = 0, pos = -1;
        for (char ch : s) {
            ch -= 'a';
            if (!nxt[u][ch])
                break;
            u = nxt[u][ch];
            if (exist[u] > 0)
                pos = u;
        }
        if (pos != -1) {
            exist[pos] = -1e9;
            return 1;
        } else
            return 0;
    }
} trie;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    i64 ans = 0;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        if (s == "what's") {
            cin >> s;
            trie.insert(s);
        } else {
            ans += trie.query(s);
        }
    }
    cout << ans << '\n';
    return 0;
}