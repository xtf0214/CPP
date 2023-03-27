#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;

int n, maxlen, src, dst; // src:起点  dst:最长路径的终点  maxlen:最长路径
vector<int> G[N];
int indeg[N], dep[N], pre[N]; // indeg:入度  dep:深度  pre:父节点

void dfs(int u) {
    for (int v : G[u]) {
        dep[v] = dep[u] + 1;
        pre[v] = u;
        if (maxlen < dep[v]) { // 更新长度更长的路径，设置当前节点为终点
            maxlen = dep[v];
            dst = v;
        }
        dfs(v);
    }
}
void print(int u) {
    if (u == -1)
        return;
    print(pre[u]);
    cout << u << " \n"[u == dst]; // 当u不是终点时空格分隔，u为终点时换行，行末空格引发防止格式错误
}
int main() {
    cin >> n;
    for (int u = 0, v, k; u < n; u++) {
        cin >> k;
        while (k--) {
            cin >> v;
            G[u].push_back(v);
            indeg[v]++;
        }
        sort(G[u].begin(), G[u].end()); // 题目要求长度相同优先输出序列小的，所以搜索子节点的顺序按照子节点大小排序
    }
    src = find(indeg, indeg + n, 0) - indeg; // 查找第一个入度为0的节点，即起点
    pre[src] = -1;
    dfs(src);
    cout << maxlen + 1 << endl; // +1是算上起点，起点的深度设置为0
    print(dst);
    return 0;
}