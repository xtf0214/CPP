#include <bits/stdc++.h>
using namespace std;

class Solution
{
    using ll = long long;
    using pii = pair<int, int>;

public:
    long long minCost(vector<int> &nums, vector<int> &cost)
    {
        int n = nums.size();
        vector<pii> a;
        for (int i = 0; i < n; i++)
            a.push_back(pii(nums[i], cost[i]));
        sort(a.begin(), a.end());

        // 前缀和
        vector<ll> f(n + 1), g(n + 1);
        for (int i = 1; i <= n; i++)
        {
            f[i] = f[i - 1] + 1LL * a[i - 1].first * a[i - 1].second;
            g[i] = g[i - 1] + a[i - 1].second;
        }

        ll ans = 1e18;
        for (int i = 1; i <= n; i++)
        {
            ll L = a[i - 1].first * g[i - 1] - f[i - 1];
            ll R = (f[n] - f[i]) - a[i - 1].first * (g[n] - g[i]);
            ans = min(ans, L + R);
        }
        return ans;
    }
};