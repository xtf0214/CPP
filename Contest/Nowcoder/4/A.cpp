/**
 * @file    :   A ZZULI
 * @author  :   Tanphoon
 * @date    :   2023/06/16 00:59
 * @version :   2023/06/16 00:59
 * @link    :   https://ac.nowcoder.com/acm/contest/38487/A
 */
#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p, sz;
    DSU(int n = 1e6) : p(n), sz(n, 1) { iota(p.begin(), p.end(), 0); }
    int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }
    void merge(int x, int y) { x = find(x), y = find(y), (x != y ? p[y] = x, sz[x] += sz[y] : 0); }
    int size(int x) { return sz[find(x)]; }
};

int main() {
    array<char, 4> w{'Z', 'U', 'L', 'I'};
    map<char, int> idx;
    for (char ch : w)
        idx[ch] = -1;
    string s;
    cin >> s;
    int n = s.size();
    // 记录w中每个字符第一次出现的位置
    for (int i = 0; i < n; i++)
        if (count(w.begin(), w.end(), s[i]))
            if (idx[s[i]] == -1)
                idx[s[i]] = i;
    DSU f(n + 1);
    // 将这四个字符第一次出现的位置和它能连接的位置合并
    for (int i = 0; i < 4; i++) {
        int bg = idx[w[i]];
        if (bg == -1)
            continue;
        for (int j = bg + 1; j < n; j++)
            if (count(w.begin() + i, w.end(), s[j]))
                f.merge(bg, j);
    }
    // 统计最大的连通块
    int mx = 0;
    for (int i = 0; i <= n; i++)
        mx = max(mx, f.size(i));
    cout << mx << '\n';
    return 0;
}