/**
 * @file    :   block
 * @author  :   Tanphoon
 * @date    :   2023/05/09 15:39
 * @version :   2023/05/09 15:39
 * @link    :
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <typename T> class Block {
    int n, t, m;
    vector<int> L, R;
    vector<T> v, sum, tag;

  public:
    Block(const vector<T> &v) // 0-index
        : n(v.size()), t(sqrt(n)), m(n / t + (n % t > 0)), v(v), sum(m), tag(m), L(m), R(m) {
        for (int i = 0; i < m; i++)
            L[i] = t * i, R[i] = min(t * (i + 1) - 1, n - 1);
        for (int i = 0; i < n; i++)
            sum[i / t] += v[i];
    }
    void modifty(int a, int b, T k) {
        int p = a / t, q = b / t;
        if (p == q) {
            for (int i = a; i <= b; i++)
                v[i] += k, sum[q] += k;
        } else {
            for (int i = a; i <= R[p]; i++)
                v[i] += k, sum[p] += k;
            for (int j = L[q]; j <= b; j++)
                v[j] += k, sum[q] += k;
            for (int i = p + 1; i <= q - 1; i++)
                sum[i] += t * k, tag[i] += k;
        }
    }
    T query(int a, int b) {
        T res = 0;
        int p = a / t, q = b / t;
        if (p == q) {
            for (int i = a; i <= b; i++)
                res += v[i] + tag[p];
        } else {
            for (int i = a; i <= R[p]; i++)
                res += v[i] + tag[p];
            for (int j = L[q]; j <= b; j++)
                res += v[j] + tag[q];
            for (int i = p + 1; i <= q - 1; i++)
                res += sum[i];
        }
        return res;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    Block<ll> seg(a);
    while (m--) {
        int op, l, r, k;
        cin >> op >> l >> r;
        if (op == 1) {
            cin >> k;
            seg.modifty(l, r, k);
        } else if (op == 2) {
            cout << seg.query(l, r) << '\n';
        }
    }
    return 0;
}