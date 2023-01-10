
/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int i = 0, j = height.size() - 1, res = 0;
        while (i < j)
        {
            if (height[i] < height[j])
                res = max(res, height[i] * (j - i)), i++;
            else
                res = max(res, height[j] * (j - i)), j--;
        }
        return res;
    }
};
// @lc code=end
