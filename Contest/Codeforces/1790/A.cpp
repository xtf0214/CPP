/**
 * @file    :   A
 * @author  :   Tanphoon
 * @date    :   2023/01/27 22:50
 * @version :   2023/01/27 22:50
 * @link    :   https://codeforces.com/contest/1790/problem/A
 */
#include <bits/stdc++.h>
using namespace std;

string PI = "314159265358979323846264338327";
int solve() {
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
        if (s[i] != PI[i])
            return i;
    return s.size();
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        cout << solve() << endl;
    return 0;
}