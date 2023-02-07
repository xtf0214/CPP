/**
 * @file    :   M
 * @author  :   Tanphoon
 * @date    :   2023/01/30 13:14
 * @version :   2023/01/30 13:14
 * @link    :   https://ac.nowcoder.com/acm/contest/46812/M
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    int a[]{1, 1, 2};
    cin >> n;
    for (int i = 0; i < n; i++)
        cout << a[i % 3] << " ";
    return 0;
}