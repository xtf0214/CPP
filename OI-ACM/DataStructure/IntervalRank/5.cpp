/**
 * @file    :   值域扫描 O(mn) 6/10
 * @author  :   Tanphoon
 * @date    :   2024/07/12 23:37
 * @version :   2024/07/12 23:37
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int a[N], d[N];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i], d[i] = a[i];
    sort(d + 1, d + 1 + n);
    int nn = unique(d + 1, d + 1 + n) - (d + 1);
    for (int i = 1; i <= n; i++)
        a[i] = lower_bound(d + 1, d + 1 + nn, a[i]) - d;
    while (m--) {
        vector<int> b(nn + 1);
        int l, r, k;
        cin >> l >> r >> k;
        for (int i = l; i <= r; i++)
            b[a[i]]++;
        int cur = 0, cnt = 0;
        for (int i = 1; i <= nn; i++)
            if (b[i]) {
                cur = i;
                cnt += b[i];
                if (cnt >= k)
                    break;
            }
        cout << d[cur] << '\n';
    }
}