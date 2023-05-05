/**
 * @file    :   Codeforces Round 869 (Div. 2) A. Politics
 * @author  :   Tanphoon
 * @date    :   2023/05/04 21:12
 * @version :   2023/05/04 21:12
 * @link    :
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int solve() {
    int n, k, ans;
    cin >> n >> k;
    ans = n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        if (i != 0 && s[i] != s[0])
            ans--;
    }
    return ans;
}
int main() {
    int T = 1;
    cin >> T;
    while (T--)
        cout << solve() << endl;
    return 0;
}