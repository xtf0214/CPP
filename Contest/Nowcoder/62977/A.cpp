/** 
 * @file    :   A
 * @author  :   Tanphoon 
 * @date    :   2023/08/12 15:20
 * @version :   2023/08/12 15:20
 * @link    :   https://ac.nowcoder.com/acm/contest/62977/A
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
        for (int j = 0; f[j] <= i && j < f.size(); j++)
            S.push_back(SG[i - f[j]]);
        SG[i] = mex(S);
    }
    return SG;
}
void work() {
    auto SG = getSG(50, {1, 2, 5});
    for (int i = 0; i < 50; i++)
        cout << "SG"
             << "[" << i << "] : " << SG[i] << "; " << '\n';
}

bool solve() {
    int n, m;
    cin >> n >> m;
    int sg = (n % 3) ^ m;
    puts(sg ? "Alice" : "Bob");
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}