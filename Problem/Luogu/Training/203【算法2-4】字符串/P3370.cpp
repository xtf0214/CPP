/**
 * @file    :   P3370 【模板】字符串哈希
 * @author  :   Tanphoon
 * @date    :   2024/05/09 22:13
 * @version :   2024/05/09 22:13
 * @link    :   https://www.luogu.com.cn/problem/P3370
 */
#include <bits/stdc++.h>
using namespace std;
using u64 = unsigned long long;

u64 get_strHash(const string &s) {
    u64 P = 131, h = 0;
    for (int i = 0; i < s.size(); i++)
        h = h * P + s[i];
    return h;
}
int main() {
    string s;
    set<u64> st;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        st.insert(get_strHash(s));
    }
    cout << st.size() << '\n';
}