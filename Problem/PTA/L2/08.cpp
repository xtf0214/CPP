// 7-8 抢红包
#include <bits/stdc++.h>
using namespace std;

const int N = 10010;
int n;

struct Node {
    int id;
    int cnt;
    double val;
} nodes[N];
bool cmp(Node &A, Node &B) {
    if (A.val != B.val)
        return A.val > B.val;
    else if (A.cnt != B.cnt)
        return A.cnt > B.cnt;
    else
        return A.id < B.id;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        nodes[i].id = i, nodes[i].cnt = 0;
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        double sum = 0;
        while (k--) {
            int x;
            double y;
            cin >> x >> y;
            nodes[x].val += y;
            nodes[x].cnt++;
            sum += y;
        }
        nodes[i].val -= sum;
    }
    sort(nodes + 1, nodes + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        printf("%d %.2f\n", nodes[i].id, nodes[i].val / 100);
    }
    return 0;
}