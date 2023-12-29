/** 
 * @file    :   特殊堆栈
 * @author  :   Tanphoon 
 * @date    :   2023/12/24 22:01
 * @version :   2023/12/24 22:01
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
    stack<int> s;
    while (n--) {
        string op;
        cin >> op;
        if (op == "Pop") {
            if (s.empty()) {
                cout << "Invalid\n";
            } else {
                bst.erase(s.top());
                cout << s.top() << '\n';
                s.pop();
            }
        } else if (op == "Push") {
            int x;
            cin >> x;
            bst.insert(x);
            s.push(x);
        } else {
            if (s.empty()) {
                cout << "Invalid\n";
            } else {
                int k = (s.size() + 1) / 2;
                int val = bst.kth(k);
                cout << val << '\n';
            }
        }
    }
}