/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 2; i++)
            for (int j = i + 1; j < n - 1; j++)
            {
                int k = lower_bound(nums.begin() + j + 1, nums.end(), -(nums[i] + nums[j])) - nums.begin();

                if (k != n)
                {
                    cout << nums[i] << " " << nums[j] << " " << nums[k] << endl;
                    ans.push_back({nums[i], nums[j], nums[k]});
                }
            }
        return ans;
    }
};
// @lc code=end
