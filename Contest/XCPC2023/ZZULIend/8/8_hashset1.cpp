// 301004 软工21——所以爱会消失对不队(马振刚\秦文杰\吕国凡)
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    string s;
    unordered_set<string> que, ans;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (s == "what's") {
            cin >> s;
            que.insert(s);
        } else {
            for (int j = s.size(); j > 0; j--) {
                string q = s.substr(0, j);
                if (que.count(q) && !ans.count(q)) {
                    ans.insert(q);
                    break;
                }
            }
        }
    }
    cout << ans.size();
    return 0;
}