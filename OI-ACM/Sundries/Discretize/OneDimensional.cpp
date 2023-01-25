/** 
 * @file    :   OneDimensional
 * @author  :   Tanphoon 
 * @date    :   2023/01/25 23:26
 * @version :   2023/01/25 23:26
 * @link    ：  https://www.luogu.com.cn/problem/P1496
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n;
ll ans;
vector<pii> a;
vector<int> d, f;
// 将a数组离散化，逆映射保存在d中。d[a']->a
int compress(vector<pii> &a, vector<int> &d) {
    for (auto &[l, r] : a)
        d.push_back(l), d.push_back(r);
    sort(d.begin(), d.end());
    d.erase(unique(d.begin(), d.end()), d.end());
    auto get = [&d](int x) { return lower_bound(d.begin(), d.end(), x) - d.begin(); };
    for (auto &[l, r] : a)
        l = get(l), r = get(r);
    return d.size();
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    a.resize(n);
    for (auto &[l, r] : a)
        cin >> l >> r;
    // 离散后修改
    f.resize(compress(a, d));
    for (auto &[l, r] : a)
        fill(f.begin() + l, f.begin() + r, 1);
    // 逆映射到离散前
    for (int i = 0; i < f.size() - 1; i++)
        if (f[i])
            ans += d[i + 1] - d[i];
    cout << ans;
    return 0;
}