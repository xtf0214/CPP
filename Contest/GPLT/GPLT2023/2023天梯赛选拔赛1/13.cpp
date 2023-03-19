#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> deg;
unordered_map<string, vector<string>> G;

vector<string> split(string s, char p) {
    vector<string> res;
    s += p;
    for (int st = 0, i = 0; i < s.size(); i++)
        if (s[i] == p) {
            string word = s.substr(st, i - st);
            res.push_back(word);
            st = i + 1;
            if (!deg.count(word))
                deg[word] = 0;
        }
    return res;
}

vector<string> topsort() {
    priority_queue<string, vector<string>, greater<string>> Q;
    for (auto &[k, v] : deg)
        if (!v)
            Q.push(k);

    vector<string> res;
    while (!Q.empty()) {
        string t = Q.top();
        Q.pop();
        res.push_back(t);
        for (auto &p : G[t])
            if (--deg[p] == 0)
                Q.push(p);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    string str;
    cin >> n;

    vector<string> last;
    for (int i = 0; i < n; i++) {
        cin >> str;
        vector<string> cur = split(str, '.');
        if (i == 0) {
            last = cur;
            continue;
        }
        if (last.size() == cur.size()) {
            for (int j = 0; j < cur.size(); j++)
                if (last[j] != cur[j]) {
                    G[last[j]].push_back(cur[j]);
                    deg[cur[j]]++;
                    break;
                }
        }
        last = cur;
    }

    vector<string> res = topsort();
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << ".\0"[i + 1 == res.size()];
    return 0;
}
