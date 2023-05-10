// P5507 机关
// https://www.luogu.com.cn/problem/P5507
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define getBin(x, i) (x >> (i * 2) & 3)
#define setBin(x, i, s) (x ^ (getBin(x, i) << (i * 2)) ^ ((s) << (i * 2)))
#define print(v) for (int i = 0; i < v.size(); cout << v[i] << " \n"[++i == v.size()])
const int N = 1 << 24;

int g[N], nxt[12][4], fa[N], ans[20], choice[N];
struct Node
{
    int state;
    double F;
    Node(int s) : state(s), F(0)
    {
        double h = 0;
        for (int i = 0; i < 12; i++)
            if (getBin(s, i))
                h += (4 - getBin(s, i)) & 3;
        h /= 2;
        F = h + g[s];
    }
    bool operator<(const Node &t) const { return F > t.F; }
};
priority_queue<Node> Q;

signed main()
{
    int button, bg = 0;
    for (int i = 0; i < 12; i++)
    {
        cin >> button;
        bg |= (button - 1) << (i * 2);
        for (int j = 0; j < 4; j++)
            cin >> nxt[i][j], --nxt[i][j];
    }
    Q.push(bg);
    g[bg] = 0;
    while (!Q.empty())
    { // u=当前总状态, b1=旋钮i的状态, b2=旋钮i连锁旋钮的状态
        int u = Q.top().state;
        Q.pop();
        if (u == 0) //开锁状态(000,000,000,000)₄=0
            break;
        int nx, v; // nx=连锁旋钮的id, v是旋转旋钮i后的总状态
        for (int i = 0; i < 12; i++)
        {
            int b1 = getBin(u, i);
            nx = nxt[i][b1];
            int b2 = getBin(u, nx);
            v = setBin(u, i, (b1 + 1) & 3);
            v = setBin(v, nx, (b2 + 1) & 3);
            if (!g[v])
            {
                g[v] = g[u] + 1;
                fa[v] = u;
                choice[v] = i + 1;
                Q.push(v);
            }
        }
    }
    vector<int> ans;
    for (int u = 0; u != bg; u = fa[u])
        ans.push_back(choice[u]);
    cout << ans.size() << endl;
    reverse(all(ans));
    print(ans);
    return 0;
}