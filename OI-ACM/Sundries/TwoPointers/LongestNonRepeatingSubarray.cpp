/** 
 * @file    :   最长不重复子数组
 * @author  :   Tanphoon 
 * @date    :   2023/10/17 00:01
 * @version :   2023/10/17 00:01
 */
#include <bits/stdc++.h>
using namespace std;

map<int, int> mp;
int cnt = 0;
void add(int x) {
    if (++mp[x] == 1)
        cnt++;
}
void del(int x) {
    if (--mp[x] == 0)
        cnt--;
}
int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int ans = 0;
    for (int i = 1, j = 1; i <= n;) {
        while (j <= n && mp[a[j]] == 0)
            add(a[j]), j++;
        ans = max(ans, cnt);
        del(a[i]), i++;
    }
    cout << ans << '\n';
    return 0;
}