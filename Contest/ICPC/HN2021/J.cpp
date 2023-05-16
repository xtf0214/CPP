/**
 * @file    :   J 甜甜圈
 * @author  :   Tanphoon
 * @date    :   2023/05/16 23:33
 * @version :   2023/05/16 23:33
 * @link    :   https://ac.nowcoder.com/acm/contest/17242/J
 */
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
const int N = 1e5 + 5;
#define id first
#define val second

int n;
pii a[N]; // 存值和下标

template <typename T> struct BIT {
    int size;
    vector<T> dat;
    BIT(int n = 0) : size(n), dat(n + 1, 0) {}
    inline int lowbit(int x) { return x & -x; }
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
};
int main() {
    int n1, n2;
    cin >> n1 >> n2;
    n = n1 + n2;
    BIT<int> bit(n);
    for (int i = n1, x; i >= 1; i--) {
        cin >> x;
        a[i] = {i, x};
        bit.add(i, 1);
    }
    for (int i = n1 + 1, x; i <= n; i++) {
        cin >> x;
        a[i] = {i, x};
        bit.add(i, 1);
    }
    a[0].id = n1;

    ll ans = 0;
    sort(a + 1, a + 1 + n, [](const auto &a, const auto &b) { return a.val > b.val; });
    for (int i = 1; i <= n; i++) {
        bit.add(a[i].id, -1);
        ans += abs(bit.get(a[i].id) - bit.get(a[i - 1].id));
    }
    cout << ans << endl;
    return 0;
}