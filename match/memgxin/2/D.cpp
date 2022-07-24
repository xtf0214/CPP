#include <bits/stdc++.h>
#define lowbit(x) x & -x
using namespace std;
using ll = long long;
const int MAX = 4e5 + 100;
ll c[MAX];
ll n, x, y;
vector<ll> nums;
int getSum(int x)
{
    int res = 0;
    for (; x; x -= lowbit(x))
        res += c[x];
    return res;
}
void add(int x, int d)
{
    for (; x <= nums.size(); x += lowbit(x))
        c[x] += d;
}
int query(int l, int r) { return getSum(r) - getSum(l - 1); }
int get(ll x) { return lower_bound(nums.begin(), nums.end(), x) - nums.begin() + 1; }
int main()
{

    cin >> n >> x >> y;
    int b[n + 1], sum_b[n + 1] = {0};
    for (int i = 1; i <= n; i++)
        cin >> b[i], b[i] -= y;
    nums.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        sum_b[i] = sum_b[i - 1] + b[i];
        nums.push_back(sum_b[i]);
        nums.push_back(sum_b[i] - x);
    }
    // 离散化
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    add(get(0), 1);
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += query(get(sum_b[i] - x), nums.size());
        add(get(sum_b[i]), 1);
    }
    cout << ans << endl;
    return 0;
}