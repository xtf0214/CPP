#include <bits/stdc++.h>
using namespace std;

map<char, char> mp;
string solve() {
    string s;
    cin >> s;
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{')
            st.push(c);
        else {
            if (st.empty()) {
                return "Extra right brackets";
            } else if (!st.empty() && mp[st.top()] == c) {
                st.pop();
            } else {
                return "Brackets not match";
            }
        }
    }
    if (st.size())
        return "Extra left brackets";
    else
        return "Brackets match";
}
int main() {
    mp['('] = ')';
    mp['['] = ']';
    mp['{'] = '}';
    cout << solve();
    return 0;
}