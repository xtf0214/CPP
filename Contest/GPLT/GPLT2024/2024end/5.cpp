/**
 * @file    :   L1-5 别再来这么多猫娘了！
 * @author  :   Tanphoon
 * @date    :   2024/04/21 15:43
 * @version :   2024/04/21 15:43
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> banWord(n);
    for (int i = 0; i < n; i++)
        cin >> banWord[i];
    int k;
    cin >> k;
    cin.get();
    string s;
    getline(cin, s);
    vector<string> split;
    int pos = 0, cnt = 0;
    while (pos != -1) {
        int mnPos = -1, cur = -1;
        for (int i = 0; i < n; i++) {
            int curPos = s.find(banWord[i]);
            if (curPos != -1 && (mnPos == -1 || mnPos > curPos)) {
                mnPos = curPos;
                cur = i;
            }
        }
        pos = mnPos;
        if (pos != -1) {
            split.push_back(s.substr(0, pos));
            s.erase(0, pos + banWord[cur].size());
        } else {
            split.push_back(s);
        }
    }
    if (split.size() - 1 < k) {
        for (int i = 0; i < split.size(); i++) {
            if (!i) {
                cout << split[i];
            } else {
                cout << "<censored>" << split[i];
            }
        }
    } else {
        cout << split.size() - 1 << '\n';
        cout << "He Xie Ni Quan Jia!" << '\n';
    }
}