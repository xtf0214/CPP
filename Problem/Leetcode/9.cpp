/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x == 0)
            return true;
        if (x < 0)
            return false;
        string num;
        for (; x; x /= 10)
            num.push_back('0' + x % 10);
        for (int i = 0, j = num.size() - 1; i < num.size(); i++, j--)
            if (num[i] != num[j])
                return false;
        return true;
    }
};
// @lc code=end
