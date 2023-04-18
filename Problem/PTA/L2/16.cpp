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
        x < y ? p[y] = x : p[x] = y;
    }
};
struct Node {
    int id, n;
    double house, area;
    bool operator<(const Node &t) { return area != t.area ? area > t.area : id < t.id; }
};
int main() {
    DisjointSet ds;
    set<int> peo;
    map<int, pair<int, int>> property;
    int n;
    cin >> n;
    while (n--) {
        int x, fa, ma, k, son, a, b;
        cin >> x >> fa >> ma >> k;
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
    map<int, vector<int>> family;
    for (int i : peo) {
        family[ds.find(i)].push_back(i);
    }
    vector<Node> ans;
    for (auto &[id, people] : family) {
        double a = 0, b = 0;
        for (int x : people) {
            a += property[x].first;
            b += property[x].second;
        }
        a /= people.size();
        b /= people.size();
        ans.push_back(Node{id, int(people.size()), a, b});
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto &e : ans) {
        printf("%04d %d %.3lf %.3lf\n", e.id, e.n, e.house, e.area);
    }
    return 0;
}