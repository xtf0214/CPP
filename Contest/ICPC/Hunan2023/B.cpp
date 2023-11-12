/** 
 * @file    :   B
 * @author  :   Tanphoon 
 * @date    :   2023/10/18 10:29
 * @version :   2023/10/18 10:29
 * @link    :   https://codeforces.com/gym/104611/problem/B
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 5;

int mex(const vector<int> &v) {
    set<int> s(v.begin(), v.end());
    for (int i = 0;; i++)
        if (s.find(i) == s.end())
            return i;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> SG(N + 1);
    for (int i = 1; i <= N; i++) {
        vector<int> S;
        ll t = sqrt(i);
        if (t * t == i) {
            for (int j = 0; j < t; j++)
                S.push_back(SG[j * t]);
            SG[i] = mex(S);
        } else if (t * t + 1 == i) {
            for (int j = 0; j <= t; j++)
                S.push_back(SG[j * t]);
            SG[i] = mex(S);
        } else {
            SG[i] = SG[i - 1];
        }
    }
    int ans = 0;
    for (int x : a)
        ans ^= SG[x];
    cout << (ans ? "First" : "Second");
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    while (T--)
        solve();
    return 0;
}