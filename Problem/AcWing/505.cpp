/**
 * @file    :   505. 火柴排队
 * @author  :   Tanphoon
 * @date    :   2024/03/07 09:02
 * @version :   2024/03/07 09:02
 * @link    :   https://www.acwing.com/problem/content/507/
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6 + 5, mod = 99'999'997;
ll cnt = 0;
void mergeSort(int a[], int l, int r) {
    if (r - l <= 1)
        return;
    int m = (l + r) / 2;
    mergeSort(a, l, m);
    mergeSort(a, m, r);
    int n1 = m - l, n2 = r - m;
    int L[n1], R[n2];
    copy(a + l, a + m, L);
    copy(a + m, a + r, R);
    for (int k = 0, i = 0, j = 0; k < n1 + n2; k++)
        if ((j >= n2) || (i < n1 && L[i] <= R[j]))
            a[l + k] = L[i++];
        else // if ((i >= n1) || (j < n2 && L[i] > R[j]))
            a[l + k] = R[j++], cnt = (cnt + n1 - i) % mod;
}

inline void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    // 将a按照b的顺序排序
    vector<pair<int, int>> v1, v2;
    for (int i = 0; i < n; i++)
        v1.push_back({a[i], i});
    sort(v1.begin(), v1.end());
    for (int i = 0; i < n; i++)
        v2.push_back({b[i], i});
    sort(v2.begin(), v2.end());
    vector<int> c(n);
    // 还原下标位置，c表示以b为基准排序后的a的每个下标
    for (int i = 0; i < n; i++)
        c[v2[i].second] = v1[i].second;

    mergeSort(c.data(), 0, n);
    cout << cnt << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}