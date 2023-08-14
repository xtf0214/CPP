#include <bits/stdc++.h>
using namespace std;
#define int long long

#ifdef _DEBUG
void print(const auto &v) {
    cerr << "{ ";
    for (auto &it : v) cerr << it << ", ";
    cerr << "}\n";
}
template<typename T> void debug(const initializer_list<T> &v) {
    for (auto &it : v) cerr << it << " ";
    cerr << '\n';
}
#endif

signed main() {
    int n;
    cin >> n;
    vector<int> p(n + 1), v(n + 1);
    
    for (int i = 1; i <= n; i++)
        cin >> p[i] >> v[i];
    
}