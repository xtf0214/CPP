#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Node = pair<int, int>;
#define ls first
#define rs second
vector<Node> tree;

void preParse(int rt) {
    if (rt == -1)
        return;
    cout << rt << " ";
    preParse(tree[rt].ls);
    preParse(tree[rt].rs);
}
void inParse(int rt) {
    if (rt == -1)
        return;
    inParse(tree[rt].ls);
    cout << rt << " ";
    inParse(tree[rt].rs);
}
void postParse(int rt) {
    if (rt == -1)
        return;
    postParse(tree[rt].ls);
    postParse(tree[rt].rs);
    cout << rt << " ";
}

int main() {
    int n;
    cin >> n;
    tree.resize(n);
    for (int i = 0, rt, ls, rs; i < n; i++) {
        cin >> rt >> ls >> rs;
        tree[rt] = {ls, rs};
    }
    inParse(0);
    return 0;
}