#include <bits/stdc++.h>
using namespace std;
struct Work
{
    int value, begin, end, prev = 0;
    bool operator<(const Work &t) { return this->end < t.end; }
};
int main()
{
    int n;
    cin >> n;
    Work a[n];
    int dp[n];
    for (int i = 0; i < n; i++)
        cin >> a[i].value >> a[i].begin >> a[i].end;
    for (int i = 0; i < n; i++)
    {
        printf("%2d:",i);
        for (int j = 0; j < a[i].begin; j++)
            printf("  ");
        for (int j = a[i].begin; j <= a[i].end; j++)
            printf("[]");
        printf("\n");
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++)
        for (int j = i - 1; j >= 0; j--)
            if (a[i].begin >= a[j].end)
                a[i].prev == j;
    for (int i = 1; i < n; i++)
        dp[i] = max(dp[a[i].prev] + a[i].value, dp[i - 1]);
}
/* 
8
5 1 4
1 3 5
8 0 6
4 4 7
6 3 8
3 5 9
2 6 10
4 8 11
*/