/**
 * @file    :   Codeforces Round 862 (Div. 2) A
 * @author  :   Tanphoon
 * @date    :   2023/04/02 22:35
 * @version :   2023/04/02 22:35
 * @link    :   https://codeforces.com/contest/1805/problem/A
 */
#include <bits/stdc++.h>
using namespace std;
int solve() {
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sum ^= x;
    }
    if (sum == 0)
        return 0;
    else if (n % 2 == 1)
        return sum;
    else
        return -1;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        cout << solve() << endl;
    return 0;
}