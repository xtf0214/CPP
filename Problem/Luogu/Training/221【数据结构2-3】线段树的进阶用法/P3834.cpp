/** 
 * @file    :   P3834 【模板】可持久化线段树 2
 * @author  :   Tanphoon 
 * @date    :   2023/05/13 19:07
 * @version :   2023/05/13 19:07
 * @link    :   https://www.luogu.com.cn/problem/P3834
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int cnt = 0;
int a[N], b[N], root[N];
struct Node {
    int l, r, sum;
} tree[N << 5];

int update(int pre, int pl, int pr, int k) {
    int rt = ++cnt;
    tree[rt].l = tree[pre].l;
    tree[rt].r = tree[pre].r;
    tree[rt].sum = tree[pre].sum + 1;
    if (pl == pr)
        return rt;
    int mid = (pl + pr) >> 1;
    if (k <= mid)
        tree[rt].l = update(tree[pre].l, pl, mid, k);
    else
        tree[rt].r = update(tree[pre].r, mid + 1, pr, k);
    return rt;
}
int query(int u, int v, int pl, int pr, int k) {
    if (pl == pr)
        return pl;
    int x = tree[tree[v].l].sum - tree[tree[u].l].sum;
    int mid = (pl + pr) >> 1;
    if (k <= x)
        return query(tree[u].l, tree[v].l, pl, mid, k);
    else
        return query(tree[u].r, tree[v].r, mid + 1, pr, k - x);
}
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }

    sort(b + 1, b + 1 + n);
    int size = unique(b + 1, b + 1 + n) - (b + 1);
    for (int i = 1; i <= n; i++)
        a[i] = lower_bound(b + 1, b + 1 + size, a[i]) - b;

    for (int i = 1; i <= n; i++) {
        root[i] = update(root[i - 1], 1, size, a[i]);
    }
    while (m--) {
        int x, y, k;
        cin >> x >> y >> k;
        int t = query(root[x - 1], root[y], 1, size, k);
        cout << b[t] << endl;
    }
    return 0;
}