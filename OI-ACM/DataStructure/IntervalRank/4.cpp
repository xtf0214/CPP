/**
 * @file    :   nth_element O(mn) 6/10
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
        nth_element(b, b + k - 1, b + nn);
        cout << b[k - 1] << '\n';
    }
}
/*
4 10
1 4 3 2
1 1 1
1 2 1
1 2 2
1 3 1
1 3 2
1 3 3
1 4 1
1 4 2
1 4 3
1 4 4
1
1
4
1
3
4
1
2
3
4
 */