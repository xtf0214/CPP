/**
 * @file    :   古风排版
 * @author  :   Tanphoon
 * @date    :   2023/12/24 22:07
 * @version :   2023/12/24 22:07
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.get();
    string s;
    getline(cin, s);
    while (s.size() % n != 0)
        s.push_back(' ');
    vector<string> ss(n);
    for (int i = 0; i < s.size(); i++)
        ss[i % n] += s[i];
    for (int i = 0; i < n; i++) {
        reverse(ss[i].begin(), ss[i].end());
        cout << ss[i] << '\n';
    }
}
