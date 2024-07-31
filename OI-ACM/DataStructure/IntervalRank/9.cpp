/**
 * @file    :   分块 O(nlogn+mlogn\sqrt(nlogn) 7/10
 * @author  :   Tanphoon
 * @date    :   2023/05/09 15:39
 * @version :   2023/05/09 15:39
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int mn = 1e9, mx = -1e9;
const int N = 1e6 + 5;
struct Block {
    int n, t, m;
    vector<int> v, tag, L, R;
    vector<vector<int>> sum;
    // 0-index
    Block(const vector<int> &v)
        : n(v.size()), t(sqrt(n)), m(n / t + (n % t > 0)), v(v), sum(m), tag(m), L(m), R(m) {
        for (int i = 0; i < m; i++)
            L[i] = t * i, R[i] = min(t * (i + 1) - 1, n - 1);
        for (int i = 0; i < n; i++)
            sum[i / t].push_back(v[i]);
        for (int i = 0; i < m; i++)
            sort(sum[i].begin(), sum[i].end());
    }
    // v[a,b]+=k
    void modifty(int a, int b, int k) {
        int p = a / t, q = b / t;
        if (p == q) {
            for (int i = a; i <= b; i++)
                v[i] += k;
            sum[p].clear();
            for (int i = L[p]; i <= R[p]; i++)
                sum[p].push_back(v[i]);
            sort(sum[p].begin(), sum[p].end());
        } else {
            for (int i = a; i <= R[p]; i++)
                v[i] += k;
            sum[p].clear();
            for (int i = L[p]; i <= R[p]; i++)
                sum[p].push_back(v[i]);
            sort(sum[p].begin(), sum[p].end());

            for (int j = L[q]; j <= b; j++)
                v[j] += k;
            sum[q].clear();
            for (int i = L[q]; i <= R[q]; i++)
                sum[q].push_back(v[i]);
            sort(sum[q].begin(), sum[q].end());

            for (int i = p + 1; i <= q - 1; i++)
                tag[i] += k;
        }
    }
    // |v[a,b] <= k|
    int query(int a, int b, int k) {
        int res = 0, p = a / t, q = b / t;
        if (p == q) {
            for (int i = a; i <= b; i++)
                res += (v[i] + tag[p] <= k);
        } else {
            vector<int> tmp;
            for (int i = a; i <= R[p]; i++)
                res += (v[i] + tag[p] <= k);
            for (int j = L[q]; j <= b; j++)
                res += (v[j] + tag[q] <= k);
            for (int i = p + 1; i <= q - 1; i++) {
                if (sum[i].front() > k - tag[i])
                    res += 0;
                else if (sum[i].back() <= k - tag[i])
                    res += sum[i].size();
                else
                    res += upper_bound(sum[i].begin(), sum[i].end(), k - tag[i]) - sum[i].begin();
            }
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
    }
    Block seg(a);
    while (m--) {
        int op = 1, l, r, k;
        cin >> l >> r >> k;
        if (op == 2) {
            mn = min(mn, mn + k);
            mx = max(mx, mx + k);
            seg.modifty(l, r, k);
        } else if (op == 1) {
            // Debug(mn, mx);
            int lb = mn - 1, rb = mx + 1;
            while (rb - lb > 1) {
                int mid = (lb + rb) / 2;
                if (seg.query(l, r, mid) < k)
                    lb = mid;
                else
                    rb = mid;
            }
            cout << rb << '\n';
        }
    }
    return 0;
}