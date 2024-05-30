/**
 * @file    :   权值树状数组
 * @author  :   Tanphoon
 * @date    :   2024/05/30 11:10
 * @version :   2024/05/30 11:10
 * @link    :   https://www.luogu.com.cn/problem/P3369
 */
#include <bits/stdc++.h>
using namespace std;
struct BIT {
    int n;
    vector<int> tr;
    BIT(int _n = 0) : n(_n), tr(n + 1, 0) {}
    inline int lowbit(int x) { return x & -x; }
    void add(int i, int x) {
        for (assert(i > 0); i <= n; i += lowbit(i))
            tr[i] += x;
    }
    int ask(int i) {
        int res = 0;
        for (i = min(i, n); i; i -= lowbit(i))
            res += tr[i];
        return res;
    }
    int rank(int x) { return 1 + ask(x - 1); } // x的排名
    int kth(int k) {                           // 第k小的数
        int x = 0;
        for (int t = 1 << __lg(n); t; t >>= 1)
            if (x + t <= n && tr[x + t] < k) {
                k -= tr[x + t];
                x += t;
            }
        return x + 1;
    }
    int pre(int x) { return kth(rank(x) - 1); } // x的前缀
    int nxt(int x) { return kth(rank(x + 1)); } // x的后缀
};

const int N = 2e7 + 1, shift = 1e7 + 1;
int main() {
    BIT bit(N);
    int n;
    cin >> n;
    for (int i = 1, op, x; i <= n; i++) {
        cin >> op >> x;
        if (op == 1) {
            bit.add(x + shift, 1);
        } else if (op == 2) {
            bit.add(x + shift, -1);
        } else if (op == 3) {
            cout << bit.rank(x + shift) << '\n';
        } else if (op == 4) {
            cout << bit.kth(x) - shift << '\n';
        } else if (op == 5) {
            cout << bit.pre(x + shift) - shift << '\n';
        } else if (op == 6) {
            cout << bit.nxt(x + shift) - shift << '\n';
        }
    }
}