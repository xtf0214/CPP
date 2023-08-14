#include <bits/stdc++.h>
using namespace std;
#define int long long

#ifdef _DEBUG
void print(const auto &v) {
    cerr << "{ ";
    for (auto &it : v)
        cerr << it << ", ";
    cerr << "}\n";
}
template <typename T> void debug(const initializer_list<T> &v) {
    for (auto &it : v)
        cerr << it << " ";
    cerr << '\n';
}
#endif

int n;
vector<int> a[3], p[3];

int calc(const vector<int> &v, int x) {
    int s = 0;
    for (int i = 1; i <= n; i++)
        s += abs(v[i] - x);
    return s;
}
int threehalf(int i) {
    auto &v = a[i];
    int l = v[1] - 1, r = v[n] + 1;
    while (r - l > 2) {
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        if (calc(v, m1) < calc(v, m2)) {
            r = m2;
        } else {
            l = m1;
        }
    }
    return (l + r) / 2;
}
int calc2(int i, int x) {
    auto &v = a[i];
    auto &s = p[i];
    int ans = 0;
    int l = 0, r = n + 1, mid;
    while (r - l > 1) {
        mid = (l + r) / 2;
        if (v[mid] < x + mid - 1)
            l = mid;
        else 
            r = mid;
    }
    ans += l * (x + x + l - 1) / 2 - (s[l]);
    ans += (s[n] - s[l]) - (n - l) * (x + l + x + n - 1) / 2;
    return ans;
}
int threehalf2(int i) {
    // cerr << "------\n";
    // cerr << i << '\n';
    auto &v = a[i];
    int l = v[1] - 1, r = v[n] - (n - 1) + 1;
    while (r - l > 2) {
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        if (calc2(i, m1) < calc2(i, m2)) {
            r = m2;
        } else {
            l = m1;
        }
    }
    return (l + r) / 2;
}
signed main() {
    cin >> n;
    for (int i = 0; i < 3; i++)
        a[i].resize(n + 1), p[i].resize(n + 1);
    
    for (int i = 1; i <= n; i++)
        cin >> a[0][i] >> a[1][i] >> a[2][i];
    
    vector<int> s(3), t(3);
    for (int i = 0; i < 3; i++) {
        sort(a[i].begin() + 1, a[i].end());
        for (int j = 1; j <= n; j++)
            p[i][j] = p[i][j - 1] + a[i][j];
        s[i] = calc(a[i], threehalf(i));
        t[i] = calc2(i, threehalf2(i));
    }
    int sum = s[0] + s[1] + s[2];
    // print(s);
    // print(t);
    int ans = 1e18;
    for (int i = 0; i < 3; i++)
        ans = min(ans, sum - s[i] + t[i]);
    cout << ans << '\n';
}