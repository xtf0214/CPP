/** 
 * @file    :   D
 * @author  :   Tanphoon 
 * @date    :   2023/08/16 13:06
 * @version :   2023/08/16 13:06
 * @link    :   https://ac.nowcoder.com/acm/contest/63602/D
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef _DEBUG
#include "DEBUG.h"
#endif
const int N = 1e6 + 5;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<ll> a{m};
    while (m > 1) {
        a.push_back((m + 1) / 2);
        m = (m + 1) / 2;
    }
    for (int i = 1; i < a.size(); i++)
        a[i] += a[i - 1];
    int id = lower_bound(a.begin(), a.end(), n) - a.begin();
    if (id < a.size()) {
        cout << id << '\n';
    } else {
        cout << a.size() - 1 + n - a.back() << '\n';
    }
    // 4 -> 2 -> 1
    // 3 -> 2 -> 1
    // 5 -> 3
    return 0;
}