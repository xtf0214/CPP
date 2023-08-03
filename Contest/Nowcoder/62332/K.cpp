/**
 * @file    :   K
 * @author  :   Tanphoon
 * @date    :   2023/08/01 11:28
 * @version :   2023/08/01 11:28
 * @link    :   https://ac.nowcoder.com/acm/contest/62332/K
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 5;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int inside = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(')
            inside = 1;
        else if (inside == ')')
            inside = 0;
        if (inside == 1 && s[i] == ',')
            s[i] == '.';
    }
    cout << s << '\n';
    return 0;
}