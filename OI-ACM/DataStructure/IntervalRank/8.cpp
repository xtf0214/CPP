/**
 * @file    :   线段树维护值域桶，线段树上二分 O((n+m)log^2(n)) 10/10
 * @author  :   Tanphoon
 * @date    :   2024/07/12 23:37
 * @version :   2024/07/12 23:37
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int a[N], b[N];
vector<int> bkt[N];
struct Node {
    int l, r;
    vector<int> num;
};
Node tree[N << 2];
void pushup(int p, int l, int r) {
    const vector<int> &L = tree[p << 1].num, &R = tree[p << 1 | 1].num;
    for (int k = 0, i = 0, j = 0; k < L.size() + R.size(); k++)
        if ((j >= R.size()) || (i < L.size() && L[i] <= R[j]))
            tree[p].num.push_back(L[i++]);
        else // if ((i >= L.size()) || (j < R.size() && L[i] > R[j]))
            tree[p].num.push_back(R[j++]);
}
void build(int p, int l, int r) {
    tree[p].l = l, tree[p].r = r;
    if (l == r) {
        tree[p].num = bkt[l];
        return;
    }
    int mid = (l + r) / 2;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    pushup(p, l, r);
}
int kth(int p, int l, int r, int k) {
    if (tree[p].l == tree[p].r)
        return tree[p].num[0];
    const vector<int> &L = tree[p << 1].num;
    int x = upper_bound(L.begin(), L.end(), r) - upper_bound(L.begin(), L.end(), l - 1);
    if (k <= x)
        return kth(p << 1, l, r, k);
    else
        return kth(p << 1 | 1, l, r, k - x);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i], b[i] = a[i];
    sort(b + 1, b + n + 1);
    int nn = unique(b + 1, b + n + 1) - (b + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(b + 1, b + nn + 1, a[i]) - b;
        bkt[a[i]].push_back(i);
    }
    build(1, 1, nn);
    while (m--) {
        int l, r, k;
        cin >> l >> r >> k;
        cout << b[a[kth(1, l, r, k)]] << '\n';
    }
    // x->a[x] x->
    // x->d[x] x'->x
}