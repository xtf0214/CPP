/**
 * @file    :   A
 * @author  :   Tanphoon
 * @date    :   2024/05/29 02:14
 * @version :   2024/05/29 02:14
 * @link    :   https://codeforces.com/gym/105184/problem/A
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s;
    cin >> s;
    set<char> se;
    for (char c : s) {
        if (c != 'i')
            se.insert(c);
    }
    cout << se.size() << '\n';
}