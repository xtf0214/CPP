// 1049 Problem  g 今年暑假不AC（第七讲）
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using vi = vector<int>;
#define bg second
#define ed first
#define all(v) v.begin(), v.end()

int main()
{
    int n;
    while (cin >> n && n)
    {
        vector<pii> work(n);
        vi pre(n), dp(n);
        dp[0] = 1;
        for (int i = 0; i < n; i++)
            cin >> work[i].bg >> work[i].ed;
        sort(all(work));
        for (int i = 0; i < n; i++)
            for (int j = i - 1; j >= 0; j--)
                if (work[j].ed <= work[i].bg)
                {
                    pre[i] = j;
                    break;
                }
        for (int i = 1; i < n; i++)
            dp[i] = max(dp[i - 1], dp[pre[i]] + 1);
        cout << dp[n - 1] << endl;
    }
    return 0;
}