#include <bits/stdc++.h>
using namespace std;

#ifdef _LQDEBUG
#define db(x) cout << #x << " = " << x << endl
#define cin fin
fstream fin("C:\\Users\\Administrator\\Desktop\\input\\8.txt");
#endif

typedef long long ll;
typedef pair<int, int> pii;
const int N = 5e5 + 5;

ll a[N];
int pre[N], nxt[N];
int main() {
    int n, k;
    cin >> n >> k;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[i] = x;
        pre[i] = i - 1;
        nxt[i] = i + 1;
        q.push({x, i});
    }
    while (k--) {
        while (a[q.top().second] != q.top().first)
            q.pop();
        int u = q.top().first;
        q.pop();
        int v = find(a, a + n, u) - a;
        a[v] = -1;
        int p1 = pre[v];
        int p2 = nxt[v];
        pre[p2] = p1;
        nxt[p1] = p2;

        if (1 <= p1) {
            a[p1] += u;
            q.push({a[p1], p1});
        }
        if (p2 <= n) {
            a[p2] += u;
            q.push({a[p2], p2});
        }
    }
    for (int i = 1; i <= n; i++)
        if (a[i] != -1)
            cout << a[i] << " ";
    return 0;
}
