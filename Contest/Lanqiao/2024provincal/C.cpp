/**
 * @file    :   C
 * @author  :   Tanphoon
 * @date    :   2024/04/13 16:12
 * @version :   2024/04/13 16:12
 * @link    :   https://www.dotcpp.com/oj/train/1118/
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    string op;
    while (cin >> op) {
        if (op == "add") {
            int x;
            cin >> x;
            a[0]++;
        } else if (op == "sync") {
            int x;
            cin >> x;
            if (a[x] < a[0])
                a[x]++;
        } else if (op == "query") {
            int mn = 1e9;
            for (int i = 0; i < n; i++)
                mn = min(mn, a[i]);
            cout << mn << '\n';
        }
    }
    return 0;
}