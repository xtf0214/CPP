/**
 * @file    :   C
 * @author  :   Tanphoon
 * @date    :   2023/01/20 14:43
 * @version :   2023/01/20 14:43
 * @link    :   https://ac.nowcoder.com/acm/contest/46811/C
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define print(v) for (int i = 0; i < v.size(); cout << v[i] << " \n"[++i == v.size()])
const int N = 1e6 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> v(n + 1);
    auto make4 = [&v](int i) {
        for (int j = 0; int x : {3, 4, 1, 2})
            v[i + j++] = x + i - 1;
    };
    auto make5 = [&v](int i) {
        for (int j = 0; int x : {4, 5, 1, 2, 3})
            v[i + j++] = x + i - 1;
    };
    auto make6 = [&v](int i) {
        for (int j = 0; int x : {4, 5, 6, 1, 2, 3})
            v[i + j++] = x + i - 1;
    };
    if (n < 4) {
        cout << -1;
        return 0;
    }
    for (int i = 1; i <= n;) {
        if (n + 1 - i == 11)
            make5(i), make6(i + 5), i += 11;
        else if (n + 1 - i == 5)
            make5(i), i += 5;

        else if (n + 1 - i == 6)
            make6(i), i += 6;
        else if (n + 1 - i == 7) {
            cout << -1;
            return 0;
        } else if (n + 1 - i >= 4)
            make4(i), i += 4;
    }
    for (int i = 1; i <= n; i++)
        cout << v[i] << " ";
    cout << endl;
    return 0;
}