/** 
 * @file    :   字符串哈希
 * @author  :   Tanphoon
 * @date    :   2024/09/16 04:47
 * @version :   2024/09/16 04:47
 * @link    :   https://www.luogu.com.cn/problem/P3370
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5, P = 131, mod = 1e9 + 7;

struct strHash {
    static vector<int> p;
    int n;
    vector<int> h;
    strHash(const string &s) : n(s.size()), h(n + 1) {
        if (!p[0])
            for (int i = p[0] = 1; i <= N; i++)
                p[i] = p[i - 1] * P;
        for (int i = 1; i <= n; i++)
            h[i] = h[i - 1] * P + s[i - 1];
    }
    int get() { return get(1, n); }
    int get(int l, int r) { return h.at(r) - h[l - 1] * p[r - l + 1]; }
};
vector<int> strHash::p(N + 1);

int main() {
    string s;
    set<int> st;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        st.insert(strHash(s).get());
    }
    cout << st.size() << '\n';
}