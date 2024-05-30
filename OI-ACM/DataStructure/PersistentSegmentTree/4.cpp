/**
 * @file    :   主席树（class）
 * @author  :   Tanphoon
 * @date    :   2023/12/13 15:51
 * @version :   2023/12/13 15:51
 * @link    :   https://www.luogu.com.cn/problem/solution/P3834
 */
#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
    struct Node {
        int l = 0, r = 0, sum = 0;
    };
    vector<Node> tr; // 节点数组
    vector<int> rt;  // 每个版本的父节点
    int n;           // 权值范围 [1,n]
    // 在版本p的基础上更新
    int update(int k, int d, int p, int l, int r) {
        int q = tr.size();   // 当前节点编号
        tr.push_back(tr[p]); // 复制父节点tr[p]到tr[q]
        if (l == r) {
            tr[q].sum += d;
            return q;
        }
        int mid = (l + r) / 2;
        if (k <= mid)
            tr[q].l = update(k, d, tr[p].l, l, mid); // 若待修节点k在[l, mid]，则更新左子树
        else
            tr[q].r = update(k, d, tr[p].r, mid + 1, r); // 否则更新右子树
        tr[q].sum = tr[tr[q].l].sum + tr[tr[q].r].sum;
        return q;
    }
    // 查询版本[p+1, q]间的第k小
    int kth(int k, int p, int q, int l, int r) {
        if (l == r)
            return l;
        int mid = (l + r) / 2;
        int x = tr[tr[q].l].sum - tr[tr[p].l].sum; // 区间[l, mid]的权值和
        if (x >= k)
            return kth(k, tr[p].l, tr[q].l, l, mid); // x>=k，则第k小在左子树
        else
            return kth(k - x, tr[p].r, tr[q].r, mid + 1, r); // 否则第k小在右子树
    }
    SegmentTree(int n) : n(n), rt(1), tr(1) {}
    void update(int k, int d) { rt.push_back(update(k, d, rt.back(), 1, n)); }
    int kth(int k, int p, int q) { return kth(k, rt[p - 1], rt[q], 1, n); }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), d;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        d.push_back(a[i]);
    }
    sort(d.begin(), d.end());
    d.erase(unique(d.begin(), d.end()), d.end());
    SegmentTree seg(d.size());
    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(d.begin(), d.end(), a[i]) - d.begin() + 1;
        seg.update(a[i], 1);
    }
    while (m--) {
        int l, r, k;
        cin >> l >> r >> k;
        int idx = seg.kth(k, l, r);
        cout << d[idx - 1] << '\n';
    }
}