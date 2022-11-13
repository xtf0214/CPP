#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
template <typename T>
using vT = vector<T>;
template <typename T>
using vvT = vector<vector<T>>;
#define y first
#define x second
#define all(v) v.begin(), v.end()
#define lowbit(x) x &(-x)
#define print(v) for (int i = 0; i < v.size(); cout << v[i] << " \n"[i++ == v.size() - 1])
const int vec[4][2]{{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
const int N = 1e6 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;

using ll = long long;
class Solution
{
public:
    int lcm(int a, int b) { return a / __gcd(a, b) * b; }
    vector<ll> Lcm;
    int subarrayLCM(vector<int> &nums, int k)
    {
        int n = nums.size();
        int ans = 0;
        Lcm.assign(n, 0);
        for (int i = 0; i < n; i++)
        {
            Lcm[i] = nums[i];
            if (Lcm[i] == k)
                ans++;
            for (int j = i + 1; j < n; j++)
            {
                Lcm[j] = lcm(Lcm[j - 1], nums[j]);
                if (Lcm[j] > k)
                    break;
                if (Lcm[j] == k)
                    ans++;
            }
        }
        return ans;
    }
};
int main()
{
    Solution res;
    vector<int> nums{};
    return 0;
}