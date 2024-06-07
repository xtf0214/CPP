/**
 * @file    :   整数三分
 * @author  :   Tanphoon
 * @date    :   2024/05/29 11:56
 * @version :   2024/05/29 11:56
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    vector<int> a{1, 2, 3, 4, 5, 6, 4, 1};
    int n = a.size();
    auto calc = [&](ll x) { return a[x]; };
    auto ternary = [&](ll l, ll r) {
        while (r - l > 2) {
            ll m1 = l + (r - l) / 3;
            ll m2 = r - (r - l) / 3;
            calc(m1) > calc(m2) ? r = m2 : l = m1; // 凸函数>，凹函数<
        }
        return (l + r) / 2;
    };
    cout << calc(ternary(-1, n)) << '\n';
}