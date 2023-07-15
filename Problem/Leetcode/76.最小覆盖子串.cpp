/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        map<char, int> mp1, mp2;
        for (char c : t)
            mp1[c]++;
        int m = mp1.size();
        int cnt = 0;
        auto add = [&](int i) {
            if (++mp2[s[i]] == mp1[s[i]] && mp1.count(s[i]))
                ++cnt;
        };
        auto del = [&](int i) {
            if (--mp2[s[i]] < mp1[s[i]] && mp1.count(s[i])) {
                --cnt;
            }
        };
        int ans = INT_MAX;
        pair<int, int> pos;
        for (int i = 0, j = 0; i < n;) {
            while (j < n && cnt < m)
                add(j++);
            if (cnt == m) {
                cout << i << " " << j << endl;
                if (ans > j - i) {
                    ans = j - i;
                    pos = {i, j};
                }
            }
            del(i++);
        }
        if (ans == INT_MAX)
            return "";
        else 
            return s.substr(pos.first, pos.second - pos.first);
    }
};
// @lc code=end

