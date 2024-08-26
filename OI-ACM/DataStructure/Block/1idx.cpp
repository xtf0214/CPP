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
    vector<int> L, R, id;
    vector<T> v, sum, tag;

  public:
    Block(const vector<T> &v) // 1-index
        : n(v.size() - 1), t(sqrt(n)), m(n / t + (n % t > 0)), L(m + 1), R(m + 1), id(n + 1), v(v),
          sum(m + 1), tag(m + 1) {
        for (int i = 1; i <= n; i++)
            id[i] = (i - 1) / t + 1, sum[id[i]] += v[i];
        for (int i = 1; i <= m; i++)
            L[i] = (i - 1) * t + 1, R[i] = min(i * t, n);
    }
    void update(int a, int b, T k) {
        int p = id[a], q = id[b];
        if (p == q) {
            for (int i = a; i <= b; i++)
                v[i] += k, sum[p] += k;
        } else {
            for (int i = a; i <= R[p]; i++)
                v[i] += k, sum[p] += k;
            for (int i = L[q]; i <= b; i++)
                v[i] += k, sum[q] += k;
            for (int i = p + 1; i <= q - 1; i++)
                sum[p] += t * k, tag[i] += k;
        }
    }
    T query(int a, int b) {
        T res = 0;
        int p = id[a], q = id[b];
        if (p == q) {
            for (int i = a; i <= b; i++)
                res += v[i] + tag[p];
        } else {
            for (int i = a; i <= R[p]; i++)
                res += v[i] + tag[p];
            for (int i = L[q]; i <= b; i++)
                res += v[i] + tag[q];
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
        int op, L, R, k;
        cin >> op >> L >> R;
        if (op == 1) {
            cin >> k;
            seg.update(L, R, k);
        } else if (op == 2) {
            cout << seg.query(L, R) << '\n';
        }
    }
    return 0;
}