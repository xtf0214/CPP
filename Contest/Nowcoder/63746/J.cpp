/**
 * @file    :   J
 * @author  :   Tanphoon
 * @date    :   2023/08/24 13:01
 * @version :   2023/08/24 13:01
 * @link    :   https://ac.nowcoder.com/acm/contest/63746/J
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, k;
vector<int> G[N];
int f[N];

void bfs(int s) {
    queue<int> q;
    memset(f, 0x3f, sizeof(f));
    f[0] = 0;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : G[u])
            if (f[v] > f[u] + 1) {
                f[v] = f[u] + 1;
                q.push(v);
            } 
    }
}

int main() {
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        G[i].push_back((i + 1) % n);
        G[i].push_back((i + k) % n);
    }
    bfs(0);
    cout << *max_element(f, f + n) << '\n';
}
