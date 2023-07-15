/** 
 * @file    :   B_Strictly_Superior
 * @author  :   Tanphoon 
 * @date    :   2023/07/15 23:39
 * @version :   2023/07/15 23:39
 * @link    :   https://atcoder.jp/contests/abc310/tasks/abc310_a
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool subset(const set<int> &a, const set<int> &b) { return includes(b.begin(), b.end(), a.begin(), a.end()); } // a > b
bool psubset(const set<int> &a, const set<int> &b) { return subset(a, b) && !subset(b, a); }

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> p(n);
    vector<set<int>> f(n);

    for (int i = 0; i < n; i++) {
        cin >> p[i];
        int x, y;
        cin >> x;
        for (int j = 0; j < x; j++) {
            int y;
            cin >> y;
            f[i].insert(y);
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            bool ok = false;
            if (p[j] < p[i] && subset(f[i], f[j]))
                ok = true;
            if (p[j] <= p[i] && psubset(f[i], f[j]))
                ok = true;
            if (ok) {
                puts("Yes");
                return 0;
            }
        }
    puts("No");
    return 0;
}