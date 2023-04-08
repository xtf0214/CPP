#include <bits/stdc++.h>
using namespace std;

#ifdef _LQDEBUG
#define db(x) cout << #x << " = " << x << endl
#define cin fin
fstream fin("C:\\Users\\Administrator\\Desktop\\input\\5.txt");
#endif

typedef pair<int, int> pii;
int main() {
    int n;
    cin >> n;
    vector<pii> v;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int a = s.front() - '0';
        int b = s.back() - '0';
        v.push_back({a, b});
    }
    int ans = 0;
    for (int i = 1, j = 0; i < n;) {
        if (v[i].first != v[j].second) {
            while (i < n && v[i].first != v[j].second) {
                i++;
                ans++;
            }
            j = i++;
        } else {
            i++;
            j = i - 1;
        }
    }
    cout << ans;
    return 0;
}
