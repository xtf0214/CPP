#include <bits/stdc++.h>
using namespace std;
int V, E;
double Z, r, sum;
struct Node {
    int plus = 0;
    double s = 0;
    vector<int> son;
};
signed main() {
    cin >> V >> Z >> r;
    vector<Node> nodes(V);
    nodes[0].s = Z;
    for (int i = 0, k; i < V; i++) {
        cin >> k;
        if (k == 0) {
            cin >> nodes[i].plus;
        } else {
            nodes[i].son.assign(k, 0);
            for (int &x : nodes[i].son)
                cin >> x;
        }
    }
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        Node h = nodes[q.front()];
        q.pop();
        if (h.son.empty())
            sum += h.s * h.plus;
        for (int v : h.son) {
            nodes[v].s = h.s * (1 - r / 100.0);
            q.push(v);
        }
    }
    cout << int(sum);
    return 0;
}