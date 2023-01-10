#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarrayGCD(vector<int> &nums, int k)
    {
        int n = nums.size(), ans = 0; // Gcd[j]=__gcd({nums[i],nums[i+1],...,nums[j]})
        vector<int> Gcd(n);
        for (int i = 0; i < n; i++)
        {
            Gcd[i] = nums[i];
            if (Gcd[i] == k)
                ans++;
            for (int j = i + 1; j < n; j++)
            {
                Gcd[j] = __gcd(Gcd[j - 1], nums[j]);
                if (Gcd[j] == k)
                    ans++;
            }
        }
        return ans;
    }
};