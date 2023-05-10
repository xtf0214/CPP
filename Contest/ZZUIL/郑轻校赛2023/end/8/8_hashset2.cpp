// 102032 计科22——有求无应队(刘家贤\吴宇扬\姬孟龙)
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    string s;
    unordered_set<string> que, ans;
    while (n--) {
        cin >> s;
        if (s == "what's") {
            cin >> s;
            que.insert(s);
        } else {
            string mxque;
            for (auto &q : que) {
                string t = s.substr(0, q.size());
                if (t == q && !ans.count(q)) {
                    if (mxque.size() < q.size())
                        mxque = q;
                }
            }
            if (mxque.size()) {
                ans.insert(mxque);
            }
        }
    }
    cout << ans.size();
    return 0;
}