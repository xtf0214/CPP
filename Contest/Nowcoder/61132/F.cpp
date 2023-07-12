/** 
 * @file    :   F
 * @author  :   Tanphoon 
 * @date    :   2023/07/13 00:36
 * @version :   2023/07/13 00:36
 * @link    :   https://ac.nowcoder.com/acm/contest/61132/F
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mp[a[i]] = i;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] != i) {
            mp[a[i]] = mp[i];
            swap(a[i], a[mp[i]]);
            mp[i] = i;
            cnt++;
        }
    }
    cout << cnt;
}