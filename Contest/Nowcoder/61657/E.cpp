/**
 * @file    :   释怀的RT
 * @author  :   Tanphoon
 * @date    :   2023/07/19 13:37
 * @version :   2023/07/19 13:37
 * @link    :   https://ac.nowcoder.com/acm/contest/61657/E
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n + 2);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        //  (i - x, i - 1)
        a[max(1, i - x)]++;
        a[i]--;
        //  (i + 1, i + x)
        a[i + 1]++;
        a[min(n + 1, i + x + 1)]--;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        a[i] += a[i - 1];
        if (a[i] > 0)
            cnt++;
    }
    cout << cnt << '\n';
    return 0;
}