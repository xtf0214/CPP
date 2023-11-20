/** 
 * @file    :   K
 * @author  :   Tanphoon 
 * @date    :   2023/11/20 15:24
 * @version :   2023/11/20 15:24
 * @link    :   https://ac.nowcoder.com/acm/contest/69987/K
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    map<string, int> mp;
    vector<string> ss(n);
    for (int i = 0; i < n; i++) {
        string s;
        int x;
        cin >> s >> x;
        mp[s] += x;
        ss[i] = s;
    }
    bool ok = 1;
    while (m--) { 
        int k;
        cin >> k;
        while (k--) {
            string s;
            int x;
            cin >> s >> x;
            mp[s] -= x;
            if (mp[s] < 0) {
                ok = 0;
                break;
            }
        }
    }
    if (!ok) { 
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for (string s : ss) {
            if (mp[s] > 0)
                cout << s << ' ' << mp[s] << '\n';
        }
    }
}