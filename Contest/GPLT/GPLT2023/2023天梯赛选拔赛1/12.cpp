#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int N = 1e5 + 5;
vector<int> G[N];        // 存图
bool vis[N];             // 标记五服以内的亲属
char sex[N];             // 记录性别
bool flag;               // 标记情侣是否为近亲
void dfs(int u, int num) // num表示第几代，从1开始
{
    if (num >= 5) // 超过五代直接退出
        return;
    for (int v : G[u]) {
        if (!vis[v]) {
            vis[v] = true; // 标记出现的人
            dfs(v, num + 1);
        } else
            flag = 1; // 五服之内出现一样的人
    }
}
int main() {
    int n, T;
    cin >> n;
    while (n--) {
        int id, fa, ma;
        scanf("%d ", &id);
        sex[id] = getchar();
        scanf(" %d %d", &fa, &ma);
        if (fa != -1) {
            G[id].push_back(fa);
            sex[fa] = 'M';
        }
        if (ma != -1) {
            G[id].push_back(ma);
            sex[ma] = 'F';
        }
    }
    cin >> T;
    while (T--) {
        int x, y;
        cin >> x >> y;
        if (sex[x] == sex[y])
            cout << "Never Mind" << endl;
        else {
            memset(vis, 0, sizeof(vis));
            vis[x] = true;
            vis[y] = true;
            flag = 0;
            dfs(x, 1);
            dfs(y, 1);
            puts(flag ? "No" : "Yes");
        }
    }
    return 0;
}
/* 
11
1 M 2 -1
2 M 3 -1
3 M 4 -1
4 M 5 -1
5 M 11 -1
6 F 7 -1
7 M 8 -1
8 M 9 -1
9 M 10 -1
10 M 11 -1
11 M -1 -1
1
1 6
 */