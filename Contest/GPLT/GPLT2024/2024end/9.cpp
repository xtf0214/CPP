/** 
 * @file    :   L2-1 鱼与熊掌
 * @author  :   Tanphoon 
 * @date    :   2024/04/21 15:46
 * @version :   2024/04/21 15:46
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mp(m + 1);
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        while (k--) {
            int x;
            cin >> x;
            mp[x].push_back(i);
        }
    }
    for (int i = 1; i <= m; i++)
        sort(mp[i].begin(), mp[i].end());
    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        vector<int> intersection;
        set_intersection(mp[a].begin(), mp[a].end(), mp[b].begin(), mp[b].end(), back_insert_iterator(intersection));
        cout << intersection.size() << '\n';
    }
}
