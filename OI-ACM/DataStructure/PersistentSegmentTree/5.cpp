/**
 * @file    :   主席树（指针实现）
 * @author  :   Tanphoon
 * @date    :   2023/12/13 15:51
 * @version :   2023/12/13 15:51
 * @link    :   https://www.luogu.com.cn/problem/solution/P3834
 */
#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
    struct Node {
        Node *l = nullptr, *r = nullptr;
        int sum = 0;
    };
    vector<Node *> rt;
    int n;
    Node *update(int k, int d, Node *p, int l, int r) {
        Node *q = new Node(*p);
        if (l == r) {
            q->sum += d;
            return q;
        }
        int mid = (l + r) / 2;
        if (k <= mid)
            q->l = update(k, d, p->l, l, mid);
        else
            q->r = update(k, d, p->r, mid + 1, r);
        q->sum = q->l->sum + q->r->sum;
        return q;
    }
    int kth(int k, Node *p, Node *q, int l, int r) {
        if (l == r)
            return l;
        int mid = (l + r) / 2;
        int x = q->l->sum - p->l->sum;
        if (x >= k)
            return kth(k, p->l, q->l, l, mid);
        else
            return kth(k - x, p->r, q->r, mid + 1, r);
    }

  public:
    SegmentTree(int n) : n(n), rt(1) {
        Node *root = new Node();
        root->l = root, root->r = root;
        rt[0] = root;
    }
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