#include <bits/stdc++.h>
using namespace std;
struct node {
    string s;
    int len;
    node(string s, int len) : s(s), len(len) {}
    bool operator<(const node &A) const { return len != A.len ? len > A.len : s < A.s; } // 正确
    // bool operator<(const node &A) const { return len > A.len; } // 错误，相同长度的set只会保留一个
};
int n, cnt = 0, ans = 0;
string str;
set<node> st;
set<string> qq;
map<string, bool> mp;

bool check(string str) {
    if (str.substr(0, 7) == "what's ")
        return 1;
    else
        return 0;
}

int main() {
    cin >> n;
    getchar();
    for (int i = 1; i <= n; i++) {
        getline(cin, str);
        if (check(str)) {
            string s = str.substr(7, str.size() - 7);
            if (qq.count(s))
                continue;
            else {
                qq.insert(s);
                mp[s] = 0;
                st.insert({s, s.size()});
            }
        } else {
            int len_str = str.size();
            for (auto i : st) {
                string s2 = i.s;
                int len = i.len;
                if (len > len_str)
                    continue;
                string str2 = str.substr(0, len);
                if (str2 == s2) {
                    if (mp[s2] == 0) {
                        mp[s2] = 1;
                        ++ans;
                        break;
                    } else
                        continue;
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
/*
8
what's modui
what's modui
what's modui
what's modiu
what's mod
moduiisfenkuai
what's modui
moduiisnotfenkuai
 */