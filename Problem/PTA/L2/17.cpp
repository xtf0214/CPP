/**
 * @file    :   7-17 最长对称子串
 * @author  :   Tanphoon
 * @date    :   2023/04/17 17:04
 * @version :   2023/04/17 17:04
 * @link    :   https://pintia.cn/problem-sets/1647005933907861504/problems/1647006411324506114
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int f[N][N];
int ans;
int main() {
    string s;
    getline(cin, s);
    int n = s.size();
    s = ' ' + s;
    for (int L = 0; L < n; L++)
        for (int i = 1, j = i + L; j <= n; i++, j++) {
            if (L == 0)
                f[i][j] = true;
            else if (L == 1) {
                f[i][j] = (s[i] == s[j]);
                
            } else if (s[i] == s[j] && f[i + 1][j - 1]) {
                f[i][j] = true;
                ans = L + 1;
            }
        }
    cout << ans;
}