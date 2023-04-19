/**
 * @file    :   7-11 智能护理中心统计
 * @author  :   Tanphoon
 * @date    :   2023/04/18 15:31
 * @version :   2023/04/18 15:31
 * @link    :
 */
#include <bits/stdc++.h>
using namespace std;

int n, m, cnt = 1;
map<string, int> id;
map<int, vector<int>> G; // 护理点-{护理点}
map<int, set<int>> son;  // 护理点-{老人}
map<int, int> fa;        // 老人-护理点
int dfs(int u) {
    int s = 0;
    if (son.count(u))
        s += son[u].size();
    for (int v : G[u])
        s += dfs(v);
    return s;
}
int getId(string &x) {
    if (!id.count(x))
        id[x] = cnt++;
    return id[x];
}

int main() {
    cin >> n >> m;
    while (m--) {
        string A, B;
        cin >> A >> B;
        if (isdigit(A[0])) {
            int a = stoi(A);
            int b = getId(B);
            fa[a] = b;
            son[b].insert(a);
        } else {
            int a = getId(A);
            int b = getId(B);
            G[b].push_back(a);
        }
    }
    char op;
    while (cin >> op && op != 'E') {
        if (op == 'T') {
            int a;
            string B;
            cin >> a >> B;
            int b = getId(B);
            if (fa.count(a))
                son[fa[a]].erase(a);
            fa[a] = b;
            son[b].insert(a);
        } else if (op == 'Q') {
            string B;
            cin >> B;
            int b = getId(B);
            int s = dfs(b);
            cout << s << endl;
        }
    }
    return 0;
}