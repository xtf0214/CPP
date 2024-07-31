/**
 * @file    :   分治 O(mn) 6/10
 * @author  :   Tanphoon
 * @date    :   2024/07/12 23:37
 * @version :   2024/07/12 23:37
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int a[N], b[N];

int quickSelect(int *a, int l, int r, int k) {
    int x = a[l], i = l, j = r;
    while (i < j) {
        while (i < j && a[j] >= x)
            j--;
        while (i < j && a[i] <= x)
            i++;
        swap(a[i], a[j]);
    }
    swap(a[i], a[l]);
    if (i == k)
        return x;
    else if (i > k)
        return quickSelect(a, l, i - 1, k);
    else
        return quickSelect(a, i + 1, r, k);
}
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
        cout << quickSelect(b, 0, nn - 1, k - 1) << '\n';
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