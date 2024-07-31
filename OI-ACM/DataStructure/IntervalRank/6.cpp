/**
 * @file    :   线段树套平衡树，线段树二分 O(m log^3 n) 7/10
 * @author  :   Tanphoon
 * @date    :   2024/07/12 23:37
 * @version :   2024/07/12 23:37
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;

int n, m;
int a[N], b[N];
struct BST {
    vector<int> num;
    friend BST operator+(const BST &lhs, const BST &rhs) {
        const vector<int> &L = lhs.num, &R = rhs.num;
        BST res;
        for (int k = 0, i = 0, j = 0; k < L.size() + R.size(); k++) {
            if ((j >= R.size()) || (i < L.size() && L[i] <= R[j]))
                res.num.push_back(L[i++]);
            else // if ((i >= L.size()) || (j < R.size() && L[i] > R[j]))
                res.num.push_back(R[j++]);
        }
        return res;
    }
    int lesscnt(int k) { return upper_bound(num.begin(), num.end(), k) - num.begin(); }
};

BST tree[N << 2];
void build(int p, int l, int r) {
    if (l == r) {
        tree[p].num.push_back(a[l]);
        return;
    }
    int mid = (l + r) / 2;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    tree[p] = tree[p << 1] + tree[p << 1 | 1];
}
int query(int p, int l, int r, int a, int b, int k) {
    if (b < l || r < a)
        return 0;
    if (a <= l && r <= b)
        return tree[p].lesscnt(k);
    int mid = (l + r) / 2;
    return query(p << 1, l, mid, a, b, k) + query(p << 1 | 1, mid + 1, r, a, b, k);
}
int kth(int l, int r, int k) {
    int lb = 0, rb = n + 1;
    while (rb - lb > 1) {
        int mid = (lb + rb) / 2;
        (query(1, 1, n, l, r, b[mid]) < k) ? lb = mid : rb = mid;
    }
    return rb;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i], b[i] = a[i];
    sort(b + 1, b + n + 1);
    build(1, 1, n);
    while (m--) {
        int l, r, k;
        cin >> l >> r >> k;
        cout << b[kth(l, r, k)] << '\n';
    }
}