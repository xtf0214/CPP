/**
 * @file    :   A
 * @author  :   Tanphoon
 * @date    :   2023/08/19 18:25
 * @version :   2023/08/19 18:25
 * @link    :   https://codeforces.com/gym/103389/problem/K
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    cin.get();
    int cnt = 0;
    while (n--) {
        string s;
        getline(cin, s);
        for (int i : s)
            if (i == '-')
                cnt++;
    }
    cout << cnt << '\n';
    return 0;
}