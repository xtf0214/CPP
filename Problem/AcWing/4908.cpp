/** 
 * @file    :   4908. 饥饿的牛
 * @author  :   Tanphoon 
 * @date    :   2023/06/15 01:36
 * @version :   2023/06/15 01:36
 * @link    :   https://www.acwing.com/activity/content/problem/content/8434/
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ll n, m;
	cin >> n >> m;
	vector<ll> a(n + 1), b(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> a[i] >> b[i];
	ll ans = 0;
	for (int i = 1; i < n; i++) {
		// 从现在到下一次给粮草，每天都吃一个还能剩多少？如果能剩下就加到下一次里
		b[i + 1] += max(b[i] - (a[i + 1] - a[i]), 0LL);
		// 从现在到下一次给粮草的天数和当前剩下的粮草数，取最小即为能吃的个数
		ans += min(b[i], a[i + 1] - a[i]);
	}
	ans += min(b[n], m + 1 - a[n]);
	cout << ans << endl;
	return 0;
}