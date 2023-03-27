#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;

// 带权并查集，储存的是集合元素个数
struct DisjointSet {
    vector<int> p, val;
    DisjointSet(int n = 1e6) : p(n), val(n, 1) { iota(p.begin(), p.end(), 0); }
    int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }
    void merge(int x, int y) {
        x = find(x), y = find(y);
        if (x != y)
            p[y] = x, val[x] += val[y];
    }
};

int n;
set<int> a[N]; // a:保存每个人的爱好

int main() {
    cin >> n;
    DisjointSet ds(n + 1); // 并查集存储人
    for (int i = 1, sz; i <= n; i++) {
        cin >> sz;
        cin.get();
        while (sz--) {
            int x;
            cin >> x;
            a[i].insert(x);
            // 如果自己与其他人有共同爱好，则并入同一个集合
            for (int j = 1; j < i; j++)
                if (a[j].count(x))
                    ds.merge(i, j);
        }
    }
    vector<int> ans;
    for (int i = 1; i <= n; i++)
        if (ds.find(i) == i) // 并查集的根节点，储存该集合内的人数
            ans.push_back(ds.val[i]);
    sort(ans.begin(), ans.end(), greater<int>()); // greater<int>控制逆序排序
    cout << ans.size() << endl; // 不同集合个数
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " \n"[i + 1 == ans.size()]; // 行末无空格输出
    return 0;
}