#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
template <typename T>
using vT = vector<T>;
template <typename T>
using vvT = vector<vector<T>>;
#define all(v) v.begin(), v.end()
#define print(v) for (int i = 0; i < v.size(); cout << v[i] << " \n"[++i == v.size()])
#define F first
#define S second
#define lowbit(x) x &(-x)
const int vec[4][2]{{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
const int N = 1e6 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;

class Solution
{
public:
    int pivotInteger(int n)
    {
        vector<int> pr(n + 1);
        for (int i = 1; i <= n; i++)
            pr[i] = i + pr[i - 1];
        for (int i = 1; i <= n; i++)
            if (pr[i] == pr[n] - pr[i - 1])
                return i;
        return -1;
    }
};
int main()
{
    Solution res;
    vector<int> nums{};
    cout << res.pivotInteger(8);
    return 0;
}