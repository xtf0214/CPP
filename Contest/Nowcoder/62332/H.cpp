/** 
 * @file    :   H
 * @author  :   Tanphoon 
 * @date    :   2023/08/01 17:58
 * @version :   2023/08/01 17:58
 * @link    :   https://ac.nowcoder.com/acm/contest/62332/H
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 5;

int a[N];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) 
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    ll s = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] <= s + 1)
            s += a[i];
        else {
            cout << s + 1 << '\n';
            return 0;
        } 
    }
    cout << s + 1 << '\n';
    return 0;
}