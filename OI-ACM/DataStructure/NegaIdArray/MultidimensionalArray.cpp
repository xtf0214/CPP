#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 多维数组
template <typename T> class Arrays {
    int n;
    vector<int> size, sz; // 每一维的一个单位的数据量
    vector<T> dat;

  public:
    Arrays(const vector<int> sz, T val = 0) : n(sz.size()), sz(sz), size(n, 1) {
        partial_sum(sz.rbegin(), sz.rend() - 1, size.rbegin() + 1, multiplies());
        dat.resize(accumulate(sz.begin(), sz.end(), 1, multiplies()), val);
    }
    T &operator[](const vector<int> idx) { return dat[inner_product(idx.begin(), idx.end(), size.begin(), 0)]; }
    void print(vector<int> s = {}, int k = 0) {
        if (k == n) {
            cout << (*this)[s] << " ";
            for (int i = n; i >= 0; i--)
                if (i == 0 || s[i - 1] != sz[i - 1] - 1) {
                    cout << string(n - i, '\n');
                    break;
                }
            return;
        }
        for (int i = 1; i < sz[k]; i++) {
            s.push_back(i);
            print(s, k + 1);
            s.pop_back();
        }
    }
};

int n = 3;
vector<int> sz{3, 4, 4};
Arrays<ll> a(sz, 1), pr(sz);

void InclusionExclusion(vector<int> s = {}, int k = 0) {
    if (k == n) {
        for (int i = 1; i < (1 << n); i++) {
            int cnt = __builtin_popcount(i);
            vector<int> r;
            for (int j = 0; j < n; j++)
                r.push_back(s[j] - (i >> j & 1));
            int sign = 1 - 2 * ((cnt + 1) & 1);
            pr[s] += sign * pr[r];
        }
        pr[s] += a[s];
        return;
    }
    for (int i = 1; i < sz[k]; i++) {
        s.push_back(i);
        InclusionExclusion(s, k + 1);
        s.pop_back();
    }
}
void dp(int d, vector<int> s = {}, int k = 0) {
    if (k == n) {
        vector<int> r(s);
        if (d < 0) {
            pr[s] += a[s];
        } else {
            --r[d];
            pr[s] += pr[r];
        }
        return;
    }
    for (int i = 1; i < sz[k]; i++) {
        s.push_back(i);
        dp(d, s, k + 1);
        s.pop_back();
    }
}
int main() {
    a.print();

    // InclusionExclusion();

    for (int i = -1; i < n; i++)
        dp(i);

    pr.print();
}