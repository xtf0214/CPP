/**
 * @file    :   H 8/11 73分
 * @author  :   Tanphoon
 * @date    :   2024/04/13 16:12
 * @version :   2024/04/13 16:12
 * @link    :   https://www.dotcpp.com/oj/train/1118/
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    map<int, vector<int>> s[3];
    while (n--) {
        int l, w, c;
        cin >> l >> w >> c;
        s[c][l].push_back(w);
    }
    for (int i = 0; i < 3; i++)
        for (auto &mp : s[i])
            sort(mp.second.begin(), mp.second.end());
    ll ans = 0;
    for (int c = 0; c < 3; c++) {
        for (auto &it1 : s[c]) {
            int l1 = it1.first;
            vector<int> w1 = it1.second;
            for (int d = 0; d < 3; d++)
                if (d != c) {
                    for (auto &it2 : s[d]) {
                        int l2 = it2.first;
                        vector<int> w2 = it2.second;
                        if (l1 <= l2)
                            break;
                        for (int i = 0, j = 0; i < w1.size() && j < w2.size();) {
                            while (j < w2.size() && w2[j] <= w1[i])
                                j++;
                            int res = w2.size() - j;
                            ans = (ans + res) % mod;
                            i++;
                        }
                    }
                }
        }
    }
    cout << ans << '\n';
}