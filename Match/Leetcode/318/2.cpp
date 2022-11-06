#include <bits/stdc++.h>
using namespace std;
using ll = long long;
class Solution
{
public:
    vector<ll> sum;
    long long query(int l, int r) { return l ? sum[r] : sum[r] - sum[l - 1]; }
    long long maximumSubarraySum(vector<int> &nums, int k)
    {
        ll ans = 0;
        int n = nums.size();
        // 前缀和
        sum = vector<ll>(n);
        map<int, int> mp;
        sum[0] = nums[0];
        for (int i = 1; i < n; i++)
            sum[i] = nums[i] + sum[i - 1];

        for (int i = 0; i < k; i++)
            mp[nums[i]]++;
        if (mp.size() == k)
            ans = max(ans, query(1, k - 1));
        for (int l = 1, r = k; r < n; l++, r++)
        {
            mp[nums[r]]++;
            if (mp.count(nums[l - 1]))
                if (--mp[nums[l - 1]] == 0)
                    mp.erase(nums[l - 1]);
            if (mp.size() == k)
                ans = max(ans, query(l, r));
        }
        return ans;
    }
};
int main()
{
    Solution res;
    vector<int> nums{1, 2, 2};
    res.maximumSubarraySum(nums, 2);
}