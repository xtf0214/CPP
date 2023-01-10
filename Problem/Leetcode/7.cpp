/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    int reverse(int x)
    {
        if (x == 0)
            return 0;
        vector<int> res;
        int ans = 0;
        int f = 1;
        if (x < 0)
            x = -x, f = -f;
        for (; x; x /= 10)
            res.push_back(x % 10);
        for (long long i = res.size() - 1, mul = 1; i >= 0; i--, mul *= 10)
            ans += res[i] * mul;
        return ans * f;
    }
};
// @lc code=end
