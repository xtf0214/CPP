/**
 * @file    :   pb_ds rb_tree
 * @author  :   Tanphoon
 * @date    :   2024/05/30 12:45
 * @version :   2024/05/30 12:45
 * @link    :   https://www.luogu.com.cn/problem/P3369
 */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

template <typename T> struct BST {
    using Node = pair<T, int>;
    tree<Node, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ver;
    map<int, int> dic;
    void insert(T x) { ver.insert({x, ++dic[x]}); } // 插入一个元素x，允许重复
    void erase(T x) { ver.erase({x, dic[x]--}); } // 删除元素x，若有重复，则删除最后一个
    int rank(T x) { return ver.order_of_key({x, 1}) + 1; } //  查询元素x的排名
    T kth(int x) { return ver.find_by_order(--x)->first; } // 查询排名为x的元素
    T pre(T x) {                                           // 查询元素x的前驱
        int idx = ver.order_of_key({x, 1}) - 1; // 无论x存不存在，idx都代表x的位置，需要-1
        return ver.find_by_order(idx)->first;
    }
    T nxt(T x) {                                 // 查询元素x的后继
        int idx = ver.order_of_key({x, dic[x]}); // 如果x不存在，那么idx就是x的后继
        if (ver.find({x, 1}) != ver.end()) // 如果x存在，那么idx是x的位置，需要+1
            idx++;
        return ver.find_by_order(idx)->first;
    }
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