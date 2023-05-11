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
    vector<int> l, r, id;
    vector<T> &v, sum, tag;
    void add(int p, int a, int b, T k) {
        sum[p] += k * (b - a + 1);
        for (int i = a; i <= b; i++)
            v[i] += k;
    }
    T ask(int p, int a, int b) {
        T res = tag[p] * (b - a + 1);
        for (int i = a; i <= b; i++)
            res += v[i];
        return res;
    }

  public:
    Block(vector<T> &v) // 1-index
        : n(v.size() - 1), t(sqrt(n)), m(n / t + (n % t > 0)), l(m + 1), r(m + 1), id(n + 1), v(v), sum(m + 1),
          tag(m + 1) {
        for (int i = 1; i <= m; i++) {
            l[i] = (i - 1) * t + 1, r[i] = min(i * t, n);
            for (int j = l[i]; j <= r[i]; j++) {
                sum[i] += v[j];
                id[j] = (j - 1) / t + 1;
            }
        }
    }
    void update(int a, int b, T k) {
        int p = id[a], q = id[b];
        if (p == q) {
            add(p, a, b, k);
        } else {
            for (int i = p + 1; i <= q - 1; i++)
                tag[i] += k;
            add(p, a, r[p], k);
            add(q, l[q], b, k);
        }
    }
    T query(int a, int b) {
        T res = 0;
        int p = id[a], q = id[b];
        if (p == q) {
            res += ask(p, a, b);
        } else {
            for (int i = p + 1; i <= q - 1; i++)
                res += sum[i] + tag[i] * (r[i] - l[i] + 1);
            res += ask(p, a, r[p]);
            res += ask(q, l[q], b);
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
            seg.update(l, r, k);
        } else if (op == 2) {
            cout << seg.query(l, r) << '\n';
        }
    }
    return 0;
}