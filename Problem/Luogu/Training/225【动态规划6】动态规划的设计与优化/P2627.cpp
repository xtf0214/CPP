/** 
 * @file    :   P2627 修剪草坪 [USACO11OPEN]Mowing the Lawn G 
 * @author  :   Tanphoon 
 * @date    :   2023/06/14 10:51
 * @version :   2023/06/14 10:51
 * @link    :   https://www.luogu.com.cn/problem/P2627
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> s(n + 1), f(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] += s[i - 1];
    }
    auto g = [&](int i) { return i > 0 ? f[i - 1] - s[i] : 0; };
    // f[i] = max(f[i - 1], {f[i - j - 1] + s[i] - s[i - j] | 1 <= j <= k})
    // for (int i = 1; i <= n; i++)
    //     for (int j = 0; j <= k; j++)
    //         f[i] = max(f[i], g(i - j) + s[i]);
    deque<int> q;
    for (int i = 0; i < n; i++) {
        while (!q.empty() && i - q.front() >= k)
            q.pop_front();
        while (!q.empty() && g(q.back()) < g(i))
            q.pop_back();
        q.push_back(i);
        f[i + 1] = max(f[i], g(q.front()) + s[i + 1]);
    }
    cout << f[n];
}