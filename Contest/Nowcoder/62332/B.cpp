/** 
 * @file    :   B
 * @author  :   Tanphoon 
 * @date    :   2023/08/01 01:39
 * @version :   2023/08/01 01:39
 * @link    :   https://ac.nowcoder.com/acm/contest/62332/B
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 5;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    int t = k;
    for (int i = 0; i < k; i++)
        if (i != a[i]) {
            t = i;
            break;
        }
    cout << t << '\n';
    return 0;
}