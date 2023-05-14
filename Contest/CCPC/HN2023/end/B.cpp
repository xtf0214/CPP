/** 
 * @file    :   Problem B. Art for Rest
 * @author  :   Tanphoon 
 * @date    :   2023/05/14 16:06
 * @version :   2023/05/14 16:06
 * @link    :   https://codeforces.com/gym/104354/problem/B
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> premax(n + 1), sufmin(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        premax[i] = max(premax[i - 1], a[i]);
    }
    sufmin[n + 1] = INT_MAX;
    for (int i = n; i >= 1; i--)
        sufmin[i] = min(sufmin[i + 1], a[i]);
    int ans = 0;
    for (int k = 1; k <= n; k++) {
        bool ok = true;
        for (int i = 1; i < ceil(1.0 * n / k); i++)
            if (premax[i * k] > sufmin[i * k + 1]) {
                ok = false;
                break;
            }
        if (ok)
            ans++;
    }
    cout << ans << endl;
}