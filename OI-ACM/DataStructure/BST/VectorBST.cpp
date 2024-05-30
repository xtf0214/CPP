/** 
 * @file    :   VectorBST
 * @author  :   Tanphoon
 * @date    :   2024/05/30 13:23
 * @version :   2024/05/30 13:23
 * @link    :   https://www.luogu.com.cn/problem/P3369
 */
#include <bits/stdc++.h>
using namespace std;

template <typename T> struct BST {
    vector<T> tr;
    void insert(T x) { tr.insert(lower_bound(tr.begin(), tr.end(), x), x); }
    void erase(T x) { tr.erase(lower_bound(tr.begin(), tr.end(), x)); }
    int rank(T x) { return lower_bound(tr.begin(), tr.end(), x) - tr.begin() + 1; }
    int kth(int x) { return tr.at(x - 1); }
    int pre(int x) { return *prev(lower_bound(tr.begin(), tr.end(), x)); }
    int nxt(int x) { return *upper_bound(tr.begin(), tr.end(), x); }
};

int main() {
    int n;
    cin >> n;
    BST<int> bst;
    for (int i = 1, op, x; i <= n; i++) {
        cin >> op >> x;
        if (op == 1) {
            bst.insert(x);
        } else if (op == 2) {
            bst.erase(x);
        } else if (op == 3) {
            cout << bst.rank(x) << '\n';
        } else if (op == 4) {
            cout << bst.kth(x) << '\n';
        } else if (op == 5) {
            cout << bst.pre(x) << '\n';
        } else if (op == 6) {
            cout << bst.nxt(x) << '\n';
        }
    }
}