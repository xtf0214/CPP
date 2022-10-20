/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int i = 0, j = 0, n = s.size();
        if (n == 0)
            return 0;
        int res = 0;
        int vis[128]{0};
        while (i < n && j < n)
        {
            if (vis[s[j]])
            {
                while (s[i] != s[j])
                    vis[s[i++]] = 0;
                i++;
            }
            vis[s[j]] = 1;
            res = max(res, j - i + 1);
            j++;
        } 
        return res;
    }
};
// @lc code=end