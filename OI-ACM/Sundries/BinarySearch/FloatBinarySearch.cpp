/**
 * @file    :   BinarySearch
 * @author  :   Tanphoon
 * @date    :   2024/05/29 11:56
 * @version :   2024/05/29 11:56
 */
#include <bits/stdc++.h>
using namespace std;
using lld = long double;
int main() {

    auto calc = [&](lld x) { return x * x - 2 < 0; };
    lld l = -1e9, r = 1e9;
    for (int t = 1; t <= 100; t++) {
        lld mid = (l + r) / 2;
        calc(mid) ? l = mid : r = mid;
    }
    cout << fixed << setprecision(10) << r << '\n';
}