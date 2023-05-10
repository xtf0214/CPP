// P2085 最小函数值
// https://www.luogu.com.cn/problem/P2085
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
vector<tuple<int, int, int>> F;
vector<int> st;
int f(int i) {
    auto &[a, b, c] = F[i];
    int x = st[i]++;
    return a * x * x + b * x + c;
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    F.resize(n);
    st.resize(n, 1);
    priority_queue<pii, vector<pii>, greater<pii>> Qmin;
    for (auto &[a, b, c] : F)
        cin >> a >> b >> c;
    for (int i = 0; i < n; i++) {
        Qmin.push({f(i), i});
    }
    for (int i = 0; i < m; i++) {
        auto [val, key] = Qmin.top();
        Qmin.pop();
        cout << val << " ";
        Qmin.push({f(key), key});
    }
    return 0;
}
