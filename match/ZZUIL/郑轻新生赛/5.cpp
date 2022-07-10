#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a[505][505] = {0};
int s[505][505] = {0};
vector<int> sum;
int main()
{
    int m, n;
    cin >> n >> m;

    for (int y = 1; y <= n; y++)
        for (int x = 1; x <= m; x++)
            cin >> a[y][x];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            s[i][j] = s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1] + a[i][j];
    sort(sum.begin(), sum.end());
    int ans = 1;
    for (int i = 1; i < sum.size(); i++)
        if (sum[i] != sum[i - 1])
            ans++;
    cout << ans << endl;
    return 0;
}