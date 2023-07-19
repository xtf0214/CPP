/**
 * @file    :   奶牛的寿命
 * @author  :   Tanphoon
 * @date    :   2023/07/19 13:13
 * @version :   2023/07/19 13:13
 * @link    :   https://ac.nowcoder.com/acm/contest/61657/I
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, logn;
    cin >> n;
    m = n;
    vector<int> a;
    while (n)
        a.push_back(n & 1), n >>= 1;
    reverse(a.begin(), a.end());
    int i = 1, j = a.size() - 1;
    while (i <= j) {
        while (i < a.size() && a[i] == 0)
            i++;
        while (j >= 1 && a[j] == 1)
            j--;
        if (i <= j)
            swap(a[i], a[j]);
    }
    int ans = 0;
    for (int i = a.size() - 1, t = 1; i >= 0; i--, t <<= 1)
        ans += a[i] * t;
    cout << m - ans;
    return 0;
}