// 1020 Problem  I	猜数字游戏的提示（第二讲）
#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define all(v) v.begin(), v.end()

int main()
{
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    for (int i = 1; cin >> n && n != 0; i++)
    {
        printf("Game %d:\n", i);
        vi a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        while (true)
        {
            map<int, int> vis;
            int A = 0, B = 0;
            for (int i = 0; i < n; i++)
            {
                cin >> b[i];
                if (a[i] == b[i])
                    A++;
                else
                    vis[a[i]]++;
            }
            if ((*max_element(all(b)) == 0))
                break;
            for (int i = 0; i < n; i++)
                if (a[i] != b[i] && (vis.find(b[i]) != vis.end() && vis[b[i]] != 0))
                    B++, vis[b[i]]--;
            printf("(%d,%d)\n", A, B);
        }
    }
    return 0;
}