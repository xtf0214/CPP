/**
 * @file    :   E
 * @author  :   Tanphoon
 * @date    :   2023/08/16 21:33
 * @version :   2023/08/16 21:33
 * @link    :   https://ac.nowcoder.com/acm/contest/63602/E
 */
#include <bits/stdc++.h>
using namespace std;

int mex(const vector<int> &v) {
    set<int> s(v.begin(), v.end());
    for (int i = 0;; i++)
        if (s.find(i) == s.end())
            return i;
}

vector<int> getSG(int n, const vector<int> &f) {
    vector<int> SG(n + 1);
    for (int i = 1; i <= n; i++) {
        vector<int> S;
        for (int j = 0; j < f.size() && i - f[j] >= 0; j++)
            S.push_back(SG[i - f[j]]);
        SG[i] = mex(S);
    }
    return SG;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    vector<int> f;
    for (int i = a; i <= b; i++)
        f.push_back(i);
    auto SG = getSG(1e4, f);
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans ^= SG[s[i]];
    puts(ans ? "C" : "Y");
    return 0;
}
