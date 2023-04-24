/**
 * @file    :   7-16 家庭房产
 * @author  :   Tanphoon
 * @date    :   2023/04/17 02:13
 * @version :   2023/04/17 02:13
 * @link    :
 */
#include <bits/stdc++.h>
using namespace std;

struct DisjointSet {
    vector<int> p;
    DisjointSet(int n = 1e6) : p(n) { iota(p.begin(), p.end(), 0); }
    int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }
    void merge(int x, int y) {
        x = find(x), y = find(y);
        x < y ? p[y] = x : p[x] = y; // 要保存家庭成员的最小编号，按照编号小的作为父节点合并
    }
};
struct Node {
    int id, n;          // 家庭成员的最小编号 家庭人口数
    double house, area; // 人均房产套数 人均房产面积
    bool operator<(const Node &t) { return area != t.area ? area > t.area : id < t.id; }
};
int main() {
    DisjointSet ds;
    set<int> peo;                      // 保存每一个人的编号
    map<int, pair<int, int>> property; // 保存每一个人的房产
    int n;
    cin >> n;
    while (n--) {
        int x, fa, ma, k, son, a, b;
        cin >> x >> fa >> ma >> k;
        // 输入之后，保存每个人的编号，并把家庭成员[自己，父，母，孩子]连接在一个并查集里
        peo.insert(x);
        if (fa != -1) {
            ds.merge(x, fa);
            peo.insert(fa);
        }
        if (ma != -1) {
            ds.merge(x, ma);
            peo.insert(ma);
        }
        while (k--) {
            cin >> son;
            ds.merge(x, son);
            peo.insert(son);
        }
        cin >> a >> b;
        property[x] = {a, b};
    }
    map<int, vector<int>> family; // 家庭成员的最小编号--家庭成员
    for (int i : peo) {
        family[ds.find(i)].push_back(i); // find(i)为i的家庭中的最小编号，把i加入这个家庭
    }
    vector<Node> ans;
    for (auto &[id, people] : family) {
        double a = 0, b = 0;
        // people为这和家庭的所有成员，累加他们的所有资产，并计算平均值
        for (int x : people) {
            a += property[x].first;
            b += property[x].second;
        }
        a /= people.size();
        b /= people.size();
        ans.push_back(Node{id, int(people.size()), a, b}); // 家庭成员的最小编号 家庭人口数 人均房产套数 人均房产面积
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto &e : ans) {
        printf("%04d %d %.3lf %.3lf\n", e.id, e.n, e.house, e.area);
    }
    return 0;
}