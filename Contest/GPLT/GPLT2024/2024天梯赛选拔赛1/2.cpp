/**
 * @file    :   心理阴影面积
 * @author  :   Tanphoon
 * @date    :   2023/12/25 09:47
 * @version :   2023/12/25 09:47
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
    int x, y;
    cin >> x >> y;
    cout << (100 * 100 / 2 - x * y / 2 - (100 - x) * y - (100 - x) * (100 - y) / 2) << '\n';
}