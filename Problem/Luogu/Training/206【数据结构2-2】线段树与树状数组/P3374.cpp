/**
 * @file    :   P3374 【模板】树状数组 1
 * @author  :   Tanphoon
 * @date    :   2023/01/12 23:03
 * @version :   2023/01/12 23:03
 * @link    :   https://www.luogu.com.cn/problem/P3374
 */
#include <bits/stdc++.h>
using namespace std;

template <typename T> struct BIT {
#define lowbit(x) (x & -x)
    int size;
    vector<T> dat;
    BIT(int n = 0) : size(n), dat(vector<T>(n + 1, 0)) {}
    void add(int i, T x) {
        for (; i <= size; i += lowbit(i))
            dat[i] += x;
    }
    T get(int i) {
        T res = 0;
        for (; i; i -= lowbit(i))
            res += dat[i];
        return res;
    }
    T query(int l, int r) { return get(r) - get(l - 1); }
};
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    BIT<int> bt(n);
    for (int i = 1, x; i <= n; i++)
        cin >> x, bt.add(i, x);
    while (m--) {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1)
            bt.add(x, y);
        else if (op == 2)
            cout << bt.query(x, y) << endl;
    }
    return 0;
}