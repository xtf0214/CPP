/** 
 * @file    :   BinarySearch
 * @author  :   Tanphoon
 * @date    :   2024/05/29 11:56
 * @version :   2024/05/29 11:56
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    // 在 1~10中找到第一个平方大于25的数

    cout <<  "before C++20\n";
    int l = 0, r = 11, x = 25;
    while (r - l > 1) {
        int mid = (l + r) / 2;
         (mid * mid <= x) ? l = mid : r = mid;
    }
    cout << r << '\n';

    cout <<  "after C++20\n";
    cout << *ranges::lower_bound(ranges::iota_view(1, 11), 25, 
        [](int x, int v) { return x * x <= v; }) << '\n';
}