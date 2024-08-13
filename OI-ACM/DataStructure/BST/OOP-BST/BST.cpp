#include "BST.h"
#include <DEBUG.h>
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    vector<int> a{45, 24, 55, 12, 37, 53, 60, 28, 40, 70};
    vector<int> b{53, 17, 78, 9, 45, 65, 94, 23, 81, 88};

    BST<int> bst1, bst2;
    for (int x : a)
        bst1.insert(x);
    for (int x : b)
        bst2.insert(x);
    BinTreeUtil(bst1.root()).print();
    BinTreeUtil(bst2.root()).print();
    return 0;
}