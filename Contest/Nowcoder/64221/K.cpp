/** 
 * @file    :   K
 * @author  :   Tanphoon 
 * @date    :   2023/08/30 13:12
 * @version :   2023/08/30 13:12
 * @link    :   https://ac.nowcoder.com/acm/contest/64221/K
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 5;

int n;
vector<int> prime;
int st[N];

void init(int n) {
    fill(st, st + N, 1);
    st[0] = st[1] = 0;
    for (int i = 2; i <= n; i++) {
        if (st[i])
            prime.push_back(i);
        for (int j = 0; j < prime.size() && i * prime[j] <= n; j++) {
            st[i * prime[j]] = 0; 
            if (i % prime[j] == 0)
                break;
        }
    }
    for (int i = 1; i <= n; i++)
        st[i] += st[i - 1];
}

void solve() {
    int l, r;
    cin >> l >> r;
    cout << st[r] - st[l - 1] << '\n';
}
int main() {
    init(1e6);
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}