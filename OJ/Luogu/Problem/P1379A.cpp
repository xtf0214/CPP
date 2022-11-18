#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
using ll = long long;
const ll dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0}; //转移数组；
ll n;
int main()
{
    cin >> n;
    queue<ll> q;
    q.push(n);
    map<ll, ll> m;
    m[n] = 0;
    while (!q.empty())
    {
        int u = q.front(); //初始状态入队列
        int c[3][3], f = 0, g = 0, n = u;
        q.pop();
        if (u == 123804765)
            break;
        for (ll i = 2; i >= 0; i--)
            for (ll j = 2; j >= 0; j--)
            {
                c[i][j] = n % 10, n /= 10;
                if (!c[i][j])
                    f = i, g = j;
            }
        for (ll i = 0; i < 4; i++)
        {
            ll nx = f + dx[i], ny = g + dy[i], ns = 0;
            if (nx < 0 || ny < 0 || nx > 2 || ny > 2)
                continue; //越界就不执行
            swap(c[nx][ny], c[f][g]);
            for (ll i = 0; i < 3; i++)
                for (ll j = 0; j < 3; j++)
                    ns = ns * 10 + c[i][j]; //矩阵转数列
            if (!m.count(ns))
            {
                m[ns] = m[u] + 1; // map去重的同时顺便统计到达这个状态所需的步数
                q.push(ns);
            }
            swap(c[nx][ny], c[f][g]); //状态复原
        }
    }
    cout << m[123804765] << endl; // map的下标直接用数列表示
    return 0;
}