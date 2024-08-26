/**
 * @file    :   根据前序遍历和中序遍历还原二叉树
 * @author  :   Tanphoon
 * @date    :   2024/07/31 21:47
 * @version :   2024/07/31 21:47
 */
#include <bits/stdc++.h>
using namespace std;
#include <DEBUG.h>

using T = int;
map<T, pair<T, T>> tree;
T createTree(basic_string_view<T> preOrder, basic_string_view<T> inOrder) {
    if (preOrder.empty() || inOrder.empty())
        return -1;
    T root = preOrder[0];
    T leftTree = inOrder.find(root);
    basic_string_view<T> inOrderLeft = inOrder.substr(0, leftTree);
    basic_string_view<T> inOrderRight = inOrder.substr(leftTree + 1);
    basic_string_view<T> preOrderLeft = preOrder.substr(1, leftTree);
    basic_string_view<T> preOrderRight = preOrder.substr(leftTree + 1);
    tree[root] = {
        createTree(preOrderLeft, inOrderLeft),
        createTree(preOrderRight, inOrderRight),
    };
    return root;
}
vector<T> ans;
void postOrder(T p) {
    if (p == -1)
        return;
    postOrder(tree[p].first);
    postOrder(tree[p].second);
    ans.push_back(p);
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    while (cin >> n) {
        ans.clear();
        tree.clear();
        basic_string<T> preOrder(n, T());
        basic_string<T> inOrder(n, T());
        for (int i = 0; i < n; i++)
            cin >> preOrder[i];
        for (int i = 0; i < n; i++)
            cin >> inOrder[i];
        T root = createTree(preOrder, inOrder);
        postOrder(root);
        BinTreeUtil(toBinTreePtr(tree, 1)).print(1);
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " \n"[i == ans.size() - 1];
    }
    return 0;
}
/* 
5 
1 2 3 4 5
2 1 4 3 5 */