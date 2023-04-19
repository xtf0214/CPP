/**
 * @file    :   7-9 插松枝
 * @author  :   Tanphoon
 * @date    :   2023/04/20 01:44
 * @version :   2023/04/20 01:44
 * @link    :
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define print(v) for (auto it = v.begin(); it != v.end(); cout << *it << " \n"[next(it++) == v.end()])

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push(x);
    }
    stack<int> box;
    while (!q.empty() || !box.empty()) {
        vector<int> tree;
        while (tree.size() < k) {
            if (tree.empty()) {
                if (!box.empty()) {
                    tree.push_back(box.top());
                    box.pop();
                } else {
                    tree.push_back(q.front());
                    q.pop();
                }
            } else {
                int t = tree.back();
                if (!box.empty() && box.top() <= t) {
                    tree.push_back(box.top());
                    box.pop();
                } else {
                    if (q.empty())
                        break;
                    int x = q.front();
                    if (x > t) {
                        if (box.size() < m)
                            box.push(x);
                        else
                            break;
                    } else {
                        tree.push_back(x);
                    }
                    q.pop();
                }
            }
        }
        print(tree);
    }
    return 0;
}