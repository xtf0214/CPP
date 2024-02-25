/**
 * @file    :   B
 * @author  :   Tanphoon
 * @date    :   2024/01/23 14:54
 * @version :   2024/01/23 14:54
 * @link    :   https://ac.nowcoder.com/acm/contest/74088/B
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a = 0, b = 0;
    string s;
    while (cin >> s) {
        for (int i = 0; i < s.size(); i++) {
            a += s[i] == '1';
            b += s[i] == '0';
        }
    }
    int g = gcd(a, b);
    a /= g, b /= g;
    if (a == 10)
        cout << "Y\n";
    else if (a == 19)
        cout << "E\n";
    else
        cout << "S\n";
}