// 7-33 简易连连看
#include <bits/stdc++.h>
using namespace std;
const int MAX = 10000 + 5;
int main()
{
    char a[10][10];
    int n, m, cnt = 0;
    cin >> n;
    for (int i = 1; i <= 2 * n; i++)
        for (int j = 1; j <= 2 * n; j++)
            cin >> a[i][j];
    cin >> m;
    for (int i = 0, x1, y1, x2, y2; i < m; i++)
    {
        cin >> y1 >> x1 >> y2 >> x2;
        if (a[y1][x1] == a[y2][x2])
        {
            a[y1][x1] = a[y2][x2] = '*';
            for (int i = 1; i <= 2 * n; i++)
                for (int j = 1; j <= 2 * n; j++)
                    cout << a[i][j] << " \n"[j == 2 * n];
        }
        else
        {
            cnt++;
            cout << "Uh-oh\n";
        }
        if (cnt >= 3)
        {
            cout << "Game Over";
            break;
        }
    }
    cout << "Congratulations!";
    return 0;
}