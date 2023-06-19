/**
 * @file    :   Codeforces Round 880 (Div. 2) 1836A
 * @author  :   Tanphoon
 * @date    :   2023/06/18 22:38
 * @version :   2023/06/18 22:38
 * @link    :   https://codeforces.com/contest/1836/problem/A
 */
#include <bits/stdc++.h>
using namespace std;

bool solve() {
    int n;
    cin >> n;
    vector<int> a(100 + 5);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x]++;
    }
    for (int i = 1; i <= 100; i++)
        if (a[i] > a[i - 1])
            return false;
    return true;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        puts(solve() ? "YES" : "NO");
    return 0;
}