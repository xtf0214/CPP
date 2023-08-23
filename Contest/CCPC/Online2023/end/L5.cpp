#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
const int N = 200005, M = N * 20;
int n, i, tot, v[N], T[N], l[M], r[M], cnt[M];
ll sum[M], f[N];
struct E {
    int a, b;
} e[N];
inline bool cmp(const E &a, const E &b) { return a.b < b.b; }
int insert(int x, int a, int b, int c, int p) {
    int y = ++tot;
    cnt[y] = cnt[x] + 1;
    sum[y] = sum[x] + p;
    if (a == b)
        return y;
    int mid = (a + b) >> 1;
    if (c <= mid)
        l[y] = insert(l[x], a, mid, c, p), r[y] = r[x];
    else
        l[y] = l[x], r[y] = insert(r[x], mid + 1, b, c, p);
    return y;
}
inline ll kth(int x, int k) {
    ll ret = 0;
    int a = 1, b = n, mid, t;
    while (a < b) {
        mid = (a + b) >> 1;
        t = cnt[l[x]];
        if (k <= t) {
            x = l[x];
            b = mid;
        } else {
            k -= t;  
            ret += sum[l[x]];
            x = r[x];
            a = mid + 1;
        }
    }
    return ret + 1LL * k * v[a];
}
inline ll ask(int x, int k) {
    ll ret = e[x].a + e[x].b;
    if (k > 1)
        ret += kth(T[x - 1], k - 1);
    return ret;
}
void solve(int l, int r, int dl, int dr) {
    int m = (l + r) >> 1, dm = 0;
    ll best;
    for (int i = dr; i >= dl && i >= m; i--) {
        ll now = ask(i, m);
        if (!dm || now < best)
            best = now, dm = i;
    }
    f[m] = best;
    if (l < m)
        solve(l, m - 1, dl, dm);
    if (r > m)
        solve(m + 1, r, dm, dr);
}
int main() {
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d%d", &e[i].a, &e[i].b);
        v[i] = e[i].a;
    }
    sort(v + 1, v + n + 1);
    sort(e + 1, e + n + 1, cmp);
    for (i = 1; i <= n; i++)
        T[i] = insert(T[i - 1], 1, n, lower_bound(v + 1, v + n + 1, e[i].a) - v, e[i].a);
    solve(1, n, 1, n);
    for (i = 1; i <= n; i++)
        printf("%lld\n", f[i]);
}