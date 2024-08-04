/** 
 * @file    :   全局第k小 log(m)log(n)
 * @author  :   Tanphoon
 * @date    :   2024/08/01 12:35
 * @version :   2024/08/01 12:35
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;

struct Query {
    int id, k; // 这个询问的编号, 这个询问的k
};

int n, m;
int ans[N]; // ans[i] 表示编号为i的询问的答案

void solve(int l, int r, vector<int> &a, vector<Query> q) {
    int m = (l + r) / 2;
    if (l == r) {
        for (int i = 0; i < q.size(); i++)
            ans[q[i].id] = l;
        return;
    }
    vector<Query> q1, q2;
    auto check = [&](int k) { return upper_bound(a.begin(), a.end(), k) - a.begin(); };
    int t = check(m);
    for (int i = 0; i < q.size(); i++)
        if (q[i].k <= t)
            q1.push_back(q[i]);
        else
            q2.push_back(q[i]);
    solve(l, m, a, q1), solve(m + 1, r, a, q2);
    return;
}
int main() {
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    vector<Query> q(m);
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        q[i] = {i, k};
    }
    solve(1, 100, a, q);
    for (int i = 0; i < m; i++)
        cout << ans[i] << '\n';
}