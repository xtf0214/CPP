#include <bits/stdc++.h>
using namespace std;
struct node
{
    int id, gold, medal, people, rank, way, R;

    double x, y;
} q[230];
struct Node
{
    int rank, way;
} w[230];
int a[230];
int cmp1(node a, node b) { return a.gold > b.gold; }
int cmp2(node a, node b) { return a.medal > b.medal; }
int cmp3(node a, node b) { return a.x > b.x; }
int cmp4(node a, node b) { return a.y > b.y; }
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        q[i].id = i;
        cin >> q[i].gold >> q[i].medal >> q[i].people;
        q[i].x = 1.0 * q[i].gold / q[i].people;
        q[i].y = 1.0 * q[i].medal / q[i].people;
    }
    for (int i = 1; i <= m; i++)
        cin >> a[i];
    sort(q, q + n, cmp1);
    for (int i = 0; i < n; i++)
    {
        q[i].way = 1;
        if (i >= 1 && q[i].gold == q[i - 1].gold)
            q[i].rank = q[i - 1].rank;
        else
            q[i].rank = i + 1;
    }
    sort(q, q + n, cmp2);
    for (int i = 0; i < n; i++)
    {
        if (i >= 1 && q[i].medal == q[i - 1].medal)
            q[i].R = q[i - 1].R;
        else
            q[i].R = i + 1;
        if (q[i].rank > q[i].R)
        {
            q[i].rank = q[i].R;
            q[i].way = 2;
        }
    }
    sort(q, q + n, cmp3);
    for (int i = 0; i < n; i++)
    {
        if (i >= 1 && q[i].x == q[i - 1].x)
            q[i].R = q[i - 1].R;
        else
            q[i].R = i + 1;
        if (q[i].rank > q[i].R)
        {
            q[i].rank = q[i].R;
            q[i].way = 3;
        }
    }
    sort(q, q + n, cmp4);
    for (int i = 0; i < n; i++)
    {
        if (i >= 1 && q[i].y == q[i - 1].y)
            q[i].R = q[i - 1].R;
        else
            q[i].R = i + 1;
        if (q[i].rank > q[i].R)
        {
            q[i].rank = q[i].R;
            q[i].way = 4;
        }
    }
    for (int i = 0; i < n; i++)
    {
        w[q[i].id].rank = q[i].rank;
        w[q[i].id].way = q[i].way;
    }
    for (int i = 1; i < m; i++)
    {
        cout << w[a[i]].rank << ":" << w[a[i]].way << " ";
    }
    cout << w[a[m]].rank << ":" << w[a[m]].way << endl;
    return 0;
}
