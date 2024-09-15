#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
#include <DEBUG.h>
#else
#define debug(...) 0
#endif
const int N = 1e6 + 5, P = 131, mod = 1e9 + 7;

struct strHash {
    static vector<int> p;
    vector<int> h;
    int n;
    strHash(const string &s) : n(s.size()), h(s.size() + 1) {
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
    cin >> s;
    int n = s.size();
    strHash h(s);
    s = ' ' + s;
    for (int L = 1; L <= n; L++) {
        int cnt = 1;
        vector<int> code{0};
        for (int i = 1; i + L - 1 <= n; i += L)
            code.push_back(h.get(i, i + L - 1));
        vector<int> pos;
        for (int i = code.size() - 1; i >= 1; i--)
            if (code[i] != code[i - 1])
                pos.push_back(i);
        if (pos.size() == 3) {
            if (n % L == 0 || (n % L != 0 && h.get(n - n % L + 1, n) == h.get(1, n % L))) {
                cout << s.substr(1, L) << ' ';
                cout << s.substr((pos[1] - 1) * L + 1, L) << endl;
                return 0;
            }
        }
    }
}
