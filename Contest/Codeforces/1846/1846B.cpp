/** 
 * @file    :   1846B
 * @author  :   Tanphoon 
 * @date    :   2023/07/07 22:43
 * @version :   2023/07/07 22:43
 * @link    :   https://codeforces.com/contest/1846/problem/B
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef _DEBUG
#include "DEBUG.h"
#endif
const int N = 1e6 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;


string s[3];
bool judge(char c) {
    for (int i = 0; i < 3; i++)    
        if (s[0][i] == c && s[1][i] == c && s[2][i] == c)
            return true;
    for (int j = 0; j < 3; j++)
        if (s[j][0] == c && s[j][1] == c && s[j][2] == c)
            return true;
    if (s[0][0] == c && s[1][1] == c && s[2][2] == c)
        return true;
    else if (s[0][2] == c && s[1][1] == c && s[2][0] == c)
        return true;
    else return false;
}
void solve() {
    cin >> s[0] >> s[1] >> s[2];
    if (judge('X'))
        puts("X");
    else if (judge('O'))
        puts("O");
    else if(judge('+'))
        puts("+");
    else
        puts("DRAW");
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}