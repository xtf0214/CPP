/**
 * @file    :   DAG
 * @author  :   Tanphoon
 * @date    :   2023/08/11 21:28
 * @version :   2023/08/11 21:28
 * @link    :
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;

vector<int> G[N];
int SG[N];

int mex(const vector<int> &v) {
    set<int> s(v.begin(), v.end());
    for (int i = 0;; i++)
        if (s.find(i) == s.end())
            return i;
}
void dfs(int u) {
    for (int v : G[u])
        dfs(v);
    vector<int> S;
    for (int v : G[u])
        S.push_back(SG[v]);
    SG[u] = mex(S);
}
int main() {
    int n, m;
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
    }
    dfs(0);
    for (int i = 0; i < n; i++)
        cout << i << ": " << SG[i] << '\n';
}
/*
5 5
0 1
1 2
0 3
1 3
3 4

0: 0
1: 2
2: 0
3: 1
4: 0
 */
