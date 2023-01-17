/**
 * @file    :   P1435 [IOI2000] 回文字串
 * @author  :   Tanphoon
 * @date    :   2023/01/18 00:04
 * @version :   2023/01/18 00:04
 * @link    :   https://www.luogu.com.cn/problem/P1435
 */
#include <bits/stdc++.h>
using namespace std;

string s;
int n;
int solve() {
    vector f(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        f[i][i] = 0; // L=0
    for (int i = 1; i < n; i++)
        f[i - 1][i] = (s[i] != s[i - 1]); // L=1
    for (int L = 2; L < n; L++)
        for (int i = 0; i + L < n; i++) {
            int j = i + L;
            f[i][j] = min(f[i + 1][j] + 1, f[i][j - 1] + 1); // i__i+1____j-1__j
            if (s[i] == s[j])
                f[i][j] = min(f[i][j], f[i + 1][j - 1]);
        }
    return f[0][n - 1];
}
int main() {
    cin >> s;
    n = s.size();
    cout << solve() << endl;
    return 0;
}