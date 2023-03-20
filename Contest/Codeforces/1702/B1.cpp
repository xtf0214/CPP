/**
 * @file    :   Codeforces Round #805 (Div. 3) B
 * @author  :   Tanphoon
 * @date    :   2022/07/10 22:35
 * @version :   2022/07/10 22:35
 * @link    :   https://codeforces.com/contest/1702/problem/B
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin >> T;
    while (T--) {
        string str;
        set<char> st;
        cin >> str;
        int ans = 0;
        for (char i : str) {
            st.insert(i);
            if (st.size() > 3) {
                st.clear();
                st.insert(i);
                ans++;
            }
        }
        cout << ans + !st.empty() << endl;
    }
    return 0;
}