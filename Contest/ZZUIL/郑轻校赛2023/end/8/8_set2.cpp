#include <bits/stdc++.h>
using namespace std;
struct Node {
    string s;
    int l;
    Node(string s) : s(s) { l = s.size(); }
    bool operator<(const Node &t) const { return l != t.l ? l > t.l : s < t.s; }
};
int n;
set<Node> que;
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
                if (s.substr(0, q.l) == q.s && !ans.count(q.s)) {
                    ans.insert(q.s);
                    break;
                }
        }
    }
    cout << ans.size();
    return 0;
}