#include <bits/stdc++.h>
using namespace std;
const int MAX = 100 + 5;
int A[MAX][MAX];
int sum[MAX];
int n, k, x;
int main()
{
    cin >> n >> k >> x;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &A[i][j]);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            if (j % 2 == 0)
            {
                if (i < 1 + (j / 2 + 1) % k + 1)
                    sum[i] += x;
                else
                    sum[i] += A[-(-i + (j / 2 + 1) % k + 1)][j];
            }
            else
            {
                sum[i] += A[i][j];
            }
        i==1 ? printf("%d", sum[i]) : printf(" %d", sum[i]);
    }
}