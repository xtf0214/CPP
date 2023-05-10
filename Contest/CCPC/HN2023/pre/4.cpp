#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 10;
const int mod = 998244353;
char s[N];
int jc[N];
struct node {
    int l = 0, r = 0;
    int cnt = 0;
    int lazy = 0;
    node operator+(const node &t) const {
        if (l == 0)
            return t;
        return node{l, t.r, cnt + t.cnt - (r < t.l), 0};
    }
} tr[N << 2];
void pushup(int rt) { tr[rt] = tr[rt << 1] + tr[rt << 1 | 1]; }
void build(int rt, int l, int r) {
    if (l == r)
        tr[rt] = node{s[l], s[l], 1, 0};
    else {
        int mid = (l + r) >> 1;
        build(rt << 1, l, mid);
        build(rt << 1 | 1, mid + 1, r);
        pushup(rt);
    }
}
void pushdown(int rt) {
    if (!tr[rt].lazy)
        return;
    tr[rt << 1].lazy = (tr[rt].lazy + tr[rt << 1].lazy) % 4;
    tr[rt << 1 | 1].lazy = (tr[rt].lazy + tr[rt << 1 | 1].lazy) % 4;
    tr[rt << 1].l += tr[rt].lazy;
    if (tr[rt << 1].l - 'A' + 1 > 4) {
        tr[rt << 1].l -= 4;
        tr[rt << 1].cnt -= 1;
    }
    tr[rt << 1].r += tr[rt].lazy;
    if (tr[rt << 1].r - 'A' + 1 > 4) {
        tr[rt << 1].r -= 4;
        tr[rt << 1].cnt += 1;
    }
    tr[rt << 1 | 1].l += tr[rt].lazy;
    if (tr[rt << 1 | 1].l - 'A' + 1 > 4) {
        tr[rt << 1 | 1].l -= 4;
        tr[rt << 1 | 1].cnt -= 1;
    }
    tr[rt << 1 | 1].r += tr[rt].lazy;
    if (tr[rt << 1 | 1].r - 'A' + 1 > 4) {
        tr[rt << 1 | 1].r -= 4;
        tr[rt << 1 | 1].cnt += 1;
    }
    tr[rt].lazy = 0;
}
void update(int rt, int l, int r, int L, int R) {
    if (l <= L && r >= R) {
        if (tr[rt].l == 'D')
            --tr[rt].cnt;
        if (tr[rt].r == 'D')
            ++tr[rt].cnt;
        if (++tr[rt].l == 'E')
            tr[rt].l = 'A';
        if (++tr[rt].r == 'E')
            tr[rt].r = 'A';
        if (++tr[rt].lazy == 4)
            tr[rt].lazy = 0;
        return;
    }
    pushdown(rt);
    int mid = (L + R) >> 1;
    if (l <= mid)
        update(rt << 1, l, r, L, mid);
    if (r >= mid + 1)
        update(rt << 1 | 1, l, r, mid + 1, R);
    pushup(rt);
}
node query(int rt, int l, int r, int L, int R) {
    if (l <= L && r >= R) {
        return tr[rt];
    } else {
        pushdown(rt);
        int mid = (L + R) >> 1;
        node ans;
        if (mid >= l)
            ans = ans + query(rt << 1, l, r, L, mid);
        if (mid < r)
            ans = ans + query(rt << 1 | 1, l, r, mid + 1, R);
        return ans;
    }
}
int ksm(int x, int y) {
    int ans = 1;
    while (y) {
        if (y & 1)
            ans = ans * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return ans;
}
int inv(int x) { return ksm(x, mod - 2); }
int C(int x, int y) {
    if ((x < y) || (x < 0) || (y < 0))
        return 0;
    return jc[x] * inv(jc[x - y]) % mod * inv(jc[y]) % mod;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    jc[0] = 1;
    for (int i = 1; i <= n; i++) {
        jc[i] = jc[i - 1] * i % mod;
    }
    cin >> s + 1;
    build(1, 1, n);
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r;
            cin >> l >> r;
            update(1, l, r, 1, n);
        } else {
            int l, r, k;
            cin >> l >> r >> k;
            int tt = query(1, l, r, 1, n).cnt;
            cout << C(r - l + 1 - tt, k - tt) << "\n";
        }
    }
}
