/**
 * @file    :   剪切粘贴
 * @author  :   Tanphoon
 * @date    :   2023/12/24 22:06
 * @version :   2023/12/24 22:06
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n;
    cin >> n;
    while (n--) {
        int l, r;
        cin >> l >> r;
        string ls, rs;
        cin >> ls >> rs;
        string cx = s.substr(l - 1, r - l + 1);
        s.erase(s.begin() + l - 1, s.begin() + r - 1 + 1);
        auto pos = s.find(ls + rs);
        if (pos == -1) {
            s += cx;
        } else {
            s.insert(pos + ls.size(), cx);
        }
    }
    cout << s << '\n';
}
