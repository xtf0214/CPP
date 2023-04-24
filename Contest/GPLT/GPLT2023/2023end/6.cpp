/** 
 * @file    :   L1-6 剪切粘贴
 * @author  :   Tanphoon 
 * @date    :   2023/04/24 12:13
 * @version :   2023/04/24 12:13
 * @link    :   
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    string ss;
    cin >> ss;
    int n;
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;
        int n = b - a + 1;
        string cx = ss.substr(a - 1, n);
        ss.erase(a - 1, n);
        string s, t;
        cin >> s >> t;
        string u = s + t;
        int p = ss.find(u);
        if (p == -1)
            ss += cx;
        else
            ss.insert(p + s.size(), cx);
    }
    cout << ss;
}