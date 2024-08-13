/**
 * @file    :   AVL树
 * @author  :   Tanphoon
 * @date    :   2024/08/11 01:40
 * @version :   2024/08/11 01:40
 */
#include "AVL.h"
#include <DEBUG.h>
#include <bits/stdc++.h>
using namespace std;

int main() {
    AVL<int> avl;
    for (int i = 1; i <= 7; i++) {
        avl.insert(i * 2);
        BinTreeUtil(avl.root()).show();
        debug(string(50, '-'));
    }
    debug(BinTreeUtil(avl.root()).arrayStorage());
    vector<string> inOrder;
    avl.travIn([&](BinNodePtr<int> p) { inOrder.push_back(p->val()); });
    debug(inOrder);
    for (int key = 1; key <= 15; key++) {
        auto node1 = avl.search(key);
        auto node2 = avl.find(key, less<int>());
        auto node3 = avl.find(key, greater<int>());
        int nearest = node1 ? node1->_val : -1;
        int _less = node2 ? node2->_val : -1;
        int _greater = node3 ? node3->_val : -1;
        Log(nearest, _less, key, _greater);
    }
    for (int i = 1; i <= 7; i++) {
        avl.erase(i * 2);
        BinTreeUtil(avl.root()).show();
        debug(string(50, '-'));
    }
}