#include <iostream>
#include <vector>
using namespace std;
int solve(int n)
{
    // 获取m的素因子
    int x = n;
    vector<int> p;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
        {
            p.push_back(i);
            while (x % i == 0)
                x /= i;
        }
    if (x > 1)
        p.push_back(x);

    int m = p.size();
    int ans = 0;
    for (int i = 1; i < (1 << m); i++)
    {
        int cnt = 0;
        int mul = 1;
        for (int j = 0; j < m; j++)
            if (i & (1 << j))
            {
                cnt++;
                mul *= p[j];
            }
        // mul*(-1)^(cnt+1)
        if (cnt % 2 == 0)
            mul = -mul;
        ans += n / mul;
    }
    return n - ans;
}
int main()
{
    int n;
    cin >> n;
    cout << solve(n);
    return 0;
}
