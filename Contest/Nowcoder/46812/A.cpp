/**
 * @file    :   A
 * @author  :   Tanphoon
 * @date    :   2023/01/30 13:08
 * @version :   2023/01/30 13:08
 * @link    :   https://ac.nowcoder.com/acm/contest/46812/A
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    if (pow(x, y) == pow(y, x))
        cout << min(x, y);
    else
        cout << (pow(x, y) > pow(y, x) ? x : y);
    return 0;
}