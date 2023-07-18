/**
 * @file    :   block2
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
    vector<T> &v, sum, tag;
    int id(int i) { return (i - 1) / t + 1; }

  public:
    Block(vector<T> &v) // 1-index
        : n(v.size() - 1), t(sqrt(n)), m(n / t + (n % t > 0)), v(v), sum(m + 1), tag(m + 1) {
        for (int i = 1; i <= n; i++)
            sum[id(i)] += v[i];
    }
    void modifty(int a, int b, T k) {
        if (id(a) == id(b)) {
            for (int i = a; i <= b; i++)
                v[i] += k, sum[id(i)] += k;
        } else {
            for (int i = a; id(i) == id(a); i++)
                v[i] += k, sum[id(i)] += k;
            for (int j = b; id(j) == id(b); j--)
                v[j] += k, sum[id(j)] += k;
            for (int p = id(a) + 1; p <= id(b) - 1; p++)
                sum[p] += t * k, tag[p] += k;
        }
    }
    T query(int a, int b) {
        T res = 0;
        if (id(a) == id(b)) {
            for (int i = a; i <= b; i++)
                res += v[i] + tag[id(i)];
        } else {
            for (int i = a; id(i) == id(a); i++)
                res += v[i] + tag[id(i)];
            for (int j = b; id(j) == id(b); j--)
                res += v[j] + tag[id(j)];
            for (int p = id(a) + 1; p <= id(b) - 1; p++)
                res += sum[p];
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