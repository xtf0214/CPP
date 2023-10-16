#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
#include "DEBUG.h"
#endif

// pi[i]: 子串 s[0, i-1] 最长的相等的真前缀与真后缀的长度
// pi[i]: s[0, pi[i]-1] == s[i-pi[i], i-1]
vector<int> prefix(string s) {
    int n = s.size();
    vector<int> pi(n + 1);
    for (int i = 1; i < n; i++) {
        int j = pi[i];
        while (j && s[i] != s[j])
            j = pi[j];
        if (s[i] == s[j])
            j++;
        pi[i + 1] = j;
    }
    return pi;
}
vector<int> kmp(string s, string p) {
    string cur = p + '#' + s;
    int n = s.size(), m = p.size();
    vector<int> pos, pi = prefix(cur);
    // cur: [0, m-1]=p, [m]="#", [m+1, m+n]=s
    for (int i = m + 1; i <= n + m; i++)
        if (pi[i + 1] == m)
            pos.push_back(i - 2 * m);
    return pos;
}
int main() {
    string s = "abcaab", p = "ab";
    cout << prefix(s) << '\n';
    cout << kmp(s, p) << '\n';
}