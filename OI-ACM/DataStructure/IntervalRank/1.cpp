/**
 * @file    :   冒泡排序 O(mn^2) 3/10
 * @author  :   Tanphoon
 * @date    :   2024/07/12 23:37
 * @version :   2024/07/12 23:37
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int a[N], b[N];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    while (m--) {
        int l, r, k;
        cin >> l >> r >> k;
        int nn = 0;
        for (int i = l; i <= r; i++)
            b[nn++] = a[i];
        for (int i = nn - 1; i >= 1; i--)
            for (int j = 1; j <= i; j++)
                if (b[j - 1] > b[j])
                    swap(b[j - 1], b[j]);
        cout << b[k - 1] << '\n';
    }
}