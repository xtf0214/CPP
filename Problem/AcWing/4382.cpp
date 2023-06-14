/** 
 * @file    :   4382. 快速打字
 * @author  :   Tanphoon 
 * @date    :   2023/06/15 01:38
 * @version :   2023/06/15 01:38
 * @link    :   https://www.acwing.com/problem/content/description/4385/
 */
#include <bits/stdc++.h>
using namespace std;
int id;

void solve() {
	string s, t;
	cin >> s >> t;
	int ans = 0;
	int i = 0, j = 0;
	while(i < s.size() && j < t.size()) {
		if (s[i] == t[j])
			i++;
		j++;
	}
	if (i == s.size())
		printf("Case #%d: %d\n", ++id, t.size() - i);
	else
		printf("Case #%d: IMPOSSIBLE\n", ++id);
}

int main() {
	int T = 1;
	cin >> T;
	while (T--)
		solve();
	return 0;
}