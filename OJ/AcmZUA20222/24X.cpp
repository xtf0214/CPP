#include <bits/stdc++.h>
using namespace std;
 
int cnt;
int c[15]; // c[i]为第i行皇后所在的列column
 
// 第k行的皇后
void dfs(int k, int n)
{
    if (k == n)
    {
        cnt++;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        int right = true;
        c[k] = i;
        for (int i = 0; i < k; i++)
            if (c[i] == c[k] || i + c[i] == k + c[k] || i - c[i] == k - c[k]) // 同列 || 同副对角线 || 同主对角线 
            {
                right = false;
                break;
            }
        if (right)
            dfs(k + 1, n);
    }
}
int main()
{
    int n;
    while (cin >> n)
    {
        cnt = 0;
        dfs(0, n);
        cout << cnt << endl;
    }
    return 0;
}