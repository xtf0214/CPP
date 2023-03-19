#include <bits/stdc++.h>
using namespace std;
const int INF = 10000000;

struct Node {
    string to;
    int dist;
    Node(string a, int b) : to(a), dist(b) {}
};

int n, k, i, j, num, Dist;
string self, enemy, str, str1;
map<string, int> m, sign;
map<string, vector<Node>> mmid;
typedef pair<int, string> P;
void dijkstra();
int main() {
    cin >> n >> k >> self >> enemy;
    for (i = 1; i < n; i++) {
        cin >> str >> num;
        m[str] = num;  // 敌人数
        sign[str] = 1; // 标记是否访问 1还没访问
    }
    m[self] = 0;
    sign[self] = 1;
    for (i = 0; i < k; i++) {
        cin >> str >> str1 >> Dist;
        mmid[str].push_back(Node(str1, Dist));
        mmid[str1].push_back(Node(str, Dist));
    }
    dijkstra();
    return 0;
}

// typedef pair<int, string> P;  first 代表到当前城市的最短距离，second代表城市
void dijkstra() {
    map<string, int> dist, CityCnt, EnemyCnt, road;
    priority_queue<P, vector<P>, greater<P>> que;
    map<string, string> Path; // first当前顶点，second当前节点的前驱节点
    vector<string> path;
    P p;
    string v, to, pre;
    int i, j;
    for (auto it = m.begin(); it != m.end(); it++) // 对各个数据初始化
    {
        dist[it->first] = INF;
        Path[it->first] = "";
        CityCnt[it->first] = 0;
        EnemyCnt[it->first] = 0;
        road[it->first] = 1;
    }
    Path[self] = "";
    dist[self] = 0;
    CityCnt[self] = 0;
    EnemyCnt[self] = 0;
    que.push(P(0, self));
    int cnt = 0;
    while (que.size()) {
        p = que.top();
        que.pop();
        v = p.second;
        if (sign[v] == 0)
            continue;
        sign[v] = 0;
        for (i = 0; i < mmid[v].size(); i++) {

            to = mmid[v][i].to;
            if (dist[v] + mmid[v][i].dist < dist[to]) {
                dist[to] = dist[v] + mmid[v][i].dist;
                Path[to] = v;
                CityCnt[to] = CityCnt[v] + 1;
                EnemyCnt[to] = EnemyCnt[v] + m[to];
                road[to] = road[v];

                que.push(P(dist[to], to));
            } else if (dist[v] + mmid[v][i].dist == dist[to]) {
                road[to] += road[v];
                if (CityCnt[v] + 1 > CityCnt[to]) {
                    Path[to] = v;
                    CityCnt[to] = CityCnt[v] + 1;
                    EnemyCnt[to] = EnemyCnt[v] + m[to];

                } else if (CityCnt[v] + 1 == CityCnt[to]) {
                    if (EnemyCnt[to] < EnemyCnt[v] + m[to]) {
                        Path[to] = v;
                        EnemyCnt[to] = EnemyCnt[v] + m[to];
                    }
                }
            }
        }
    }
    pre = Path[enemy];
    path.push_back(enemy);

    while (pre != "") {
        path.push_back(pre);
        pre = Path[pre];
    }

    reverse(path.begin(), path.end());
    int flag = 0;
    for (i = 0; i < path.size(); i++) {
        if (flag)
            cout << "->";
        cout << path[i];
        flag = 1;
    }
    cout << endl << road[enemy] << " " << dist[enemy] << " " << EnemyCnt[enemy];
}