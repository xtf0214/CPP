#include <bits/stdc++.h>
using namespace std;
int n;
set<string, greater<string>> que;
set<string> ans;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        if (s == "what's") {
            cin >> s;
            que.insert(s);
        } else {
            for (auto &q : que)
                if (s.substr(0, q.size()) == q && !ans.count(q)) {
                    ans.insert(q);
                    break;
                }
        }
    }
    cout << ans.size();
    return 0;
}