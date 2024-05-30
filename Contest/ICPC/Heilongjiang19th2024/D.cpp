/**
 * @file    :   D
 * @author  :   Tanphoon
 * @date    :   2024/05/29 00:53
 * @version :   2024/05/29 00:53
 * @link    :   https://codeforces.com/gym/105163/problem/D
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;
void sovle() {
    int n, hpa, hpb;
    cin >> n >> hpa >> hpb;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        if (b[i] == -1)
            b[i] = INF;
    }
    ll sa = 0, sb = 0;
    // 格挡牌放在最后边
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++) {
        // 有一方格挡，那么后面的不用比了，全是平局
        if (a[i] == -1 || b[i] == INF) {
            cout << "no\n";
            return;
        }
        sa += a[i], sb += b[i];
        if (sa >= hpb && sb < hpa) {
            cout << "yes\n";
            return;
        }
    }
    cout << "no\n";
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        sovle();
    }
}