/**
 * @file    :   C   Alice and Bob
 * @author  :   Tanphoon
 * @date    :   2023/05/16 14:57
 * @version :   2023/05/16 14:57
 * @link    :   https://ac.nowcoder.com/acm/contest/17148/C
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 5;

int a[N], f[N];
ll s[N];
int n, m, k, cnt;
map<int, int> mp;

void add(int x) {
    if (++mp[a[x]] == 1)
        cnt++;
}
void del(int x) {
    if (--mp[a[x]] == 0)
        cnt--;
}

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    // 尺取法，f[i] 表示区间 [i, f[i]] 中有k个不同的数
    for (int l = 1, r = 1; l <= n; l++) {
        while (cnt < k && r <= n)
            add(r++);
        if (cnt == k)
            f[l] = r - 1;
        else
            f[l] = n + 1;
        del(l);
    }
    // 计算f的前缀和
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + f[i];

    ll ans = 0;
    while (m--) {
        ll l1, r1;
        cin >> l1 >> r1;
        int l = min(l1 ^ ans, r1 ^ ans) + 1;
        int r = max(l1 ^ ans, r1 ^ ans) + 1;
        // 二分
        ll p = upper_bound(f + 1, f + 1 + n, r) - f - 1;

        ans = 0;
        if (p >= l)
            ans = (r + 1) * (p - l + 1) - (s[p] - s[l - 1]);
        cout << ans << endl;
    }
}