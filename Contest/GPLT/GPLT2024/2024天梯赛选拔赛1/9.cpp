/**
 * @file    :   插松枝
 * @author  :   Tanphoon
 * @date    :   2023/12/24 22:37
 * @version :   2023/12/24 22:37
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    reverse(a.begin(), a.end());
    stack<int> box;
    while (!a.empty() || !box.empty()) {
        vector<int> tree;
        while (tree.size() < k) {
            if (tree.empty()) {     // 松枝干为空
                if (!box.empty()) { // 从盒子里取
                    tree.push_back(box.top());
                    box.pop();
                } else {           // 从推送器取
                    if (a.empty()) // 小盒子中最上面的松针不满足要求，但推送器上已经没有松针了
                        break;
                    tree.push_back(a.back());
                    a.pop_back();
                }
            } else {                                            // 松枝干非空
                if (!box.empty() && box.top() <= tree.back()) { // 从盒子里取
                    tree.push_back(box.top());
                    box.pop();
                } else {           // 从推送器取
                    if (a.empty()) // 小盒子中最上面的松针不满足要求，但推送器上已经没有松针了
                        break;
                    if (a.back() <= tree.back()) { // 推送器满足要求
                        tree.push_back(a.back());
                        a.pop_back();
                    } else {                   // 推送器不满足要求
                        if (box.size() >= m) { // 小盒子已经满了，但推送器上取到的松针仍然不满足要求。
                            break;
                        } else { // 如果推送器上拿到的仍然不满足要求，就把拿到的这片堆放到小盒子里，继续去推送器上取下一片。
                            box.push(a.back());
                            a.pop_back();
                        }
                    }
                }
            }
        }
        // 手中的松枝干上已经插满了松针，将之放到成品篮里，开始下一根松枝的制作。
        for (int i = 0; i < tree.size(); i++)
            cout << tree[i] << " \n"[i == tree.size() - 1];
    }
}
