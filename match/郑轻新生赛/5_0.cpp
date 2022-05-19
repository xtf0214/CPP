#include <bits/stdc++.h>
using namespace std;

const int MAX = 505;
// int s[MAX][MAX][MAX][MAX];
int a[MAX][MAX];
list<int> sum[MAX][MAX];
int main()
{
    int n, m, ans = 0;
    cin >> n >> m;
    int ****s = new int ***[n + 1];
    for (int i = 0; i <= n; i++)
    {
        s[i] = new int **[m + 1];
        for (int j = 0; j <= m; j++)
        {
            s[i][j] = new int *[n + 1];
            for (int k = 0; k <= n; k++)
            {
                s[i][j][k] = new int[m + 1];
                memset(s[i][j][k], 0, m + 1);
            }
        }
    }
    for (int y = 1; y <= n; y++)
        for (int x = 1; x <= m; x++)
            cin >> a[y][x];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int y = i; y <= n; y++)
                for (int x = j; x <= m; x++)
                {
                    if (i == 1 && j == 1)
                        s[i][j][y][x] = s[i][j][y][x - 1] + s[i][j][y - 1][x] - s[i][j][y - 1][x - 1] + a[y][x];
                    else if (j == 1)
                        s[i][j][y][x] = s[i - 1][j][y][x] - s[i - 1][j][i - 1][x];
                    else
                        s[i][j][y][x] = s[i][j - 1][y][x] - s[i][j - 1][y][j - 1];
                    sum[y - i + 1][x - j + 1].push_back(s[i][j][y][x]);
                }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            sum[i][j].unique();
            // sum[i][j].sort();
            ans += sum[i][j].size();
            printf("%dx%d方形个数: %d list: ", i, j, sum[i][j].size());
            for (int k : sum[i][j])
                cout << k << " ";
            cout << endl;
        }
    cout << ans;
    return 0;
}