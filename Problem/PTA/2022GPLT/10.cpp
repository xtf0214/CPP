/**
 * @file    :   10
 * @author  :   Tanphoon
 * @date    :   2023/02/22 03:16
 * @version :   2023/02/22 03:16
 */
#include <bits/stdc++.h>
using namespace std;
using pss = pair<string, string>;

int main() {
    int n;
    cin >> n;
    vector<pss> p(n);
    for (int i = 0; i < n; i++) {
        string s1, s2;
        char op;
        cin >> s1;
        scanf(" %c ", &op);
        cin >> s2;
        p[i] = {s1, s2};
    }
    sort(p.begin(), p.end());

    if (p.front().first != "00:00:00")
        cout << "00:00:00 - " << p.front().first << endl;
    for (int i = 0; i < n - 1; i++)
        if (p[i].second != p[i + 1].first)
            cout << p[i].second << " - " << p[i + 1].first << endl;
    if (p.back().second != "23:59:59")
        cout << p.back().second << " - 23:59:59" << endl;
    return 0;
}
