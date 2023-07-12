/** 
 * @file    :   G
 * @author  :   Tanphoon 
 * @date    :   2023/07/13 00:38
 * @version :   2023/07/13 00:38
 * @link    :   https://ac.nowcoder.com/acm/contest/61132/G
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    string a;
    cin >> a;
    vector<int> ans;
    for (int i = 0, j = 0; i < n;) {
        while (j < n && a[j] == a[i])
            j++;
        if (a[i] == '1') {
            ans.push_back(j - i);
        }
        i = j;
    }
    sort(ans.begin(), ans.end(), greater<int>());
    if (ans.size() == 0) {
        cout << 0;
    } else if (ans.size() == 1) {
        cout << ans[0];
    } else {
        cout << ans[0] + ans[1];
    }
    return 0;
}
