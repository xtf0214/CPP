#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    map<string, int> mp1, mp2, mp3;
    vector<string> s1(n), s2(m);
    vector<string> s3, s4;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (mp1[s] == 0) {
            s3.push_back(s);
            mp1[s] = 1;
        }
    }
    for (int j = 0; j < m; j++) {
        string s;
        cin >> s;
        if (mp2[s] == 0) {
            s4.push_back(s);
            mp2[s] = 1;
        }
    }
    n = s3.size(), m = s4.size();
    vector<string> ans;
    for (int i = 0, j = 0; i < n || j < m; i++, j++) {
        string t1 = s3[i], t2 = s4[i];
        if (i < n && mp3[t1] == 0) {
            ans.push_back(t1);
            mp3[t1] = 1;
        }
        if (j < m && mp3[t2] == 0) {
            ans.push_back(t2);
            mp3[t2] = 1;
        }
    }
    for (string s : ans)
        cout << s << '\n';
}