/** 
 * @file    :   G
 * @author  :   Tanphoon 
 * @date    :   2023/09/07 14:28
 * @version :   2023/09/07 14:28
 * @link    :   https://ac.nowcoder.com/acm/contest/39585/G
 */
#include <bits/stdc++.h>
using namespace std;
using Node = pair<int, int>;

int main() {
    string s;
    cin >> s;
    priority_queue<Node> q;
    int cnt[26] = {0};
    for (char c : s)
        cnt[c - 'a']++;
    for (int i = 0; i < 26; i++)
        q.push({cnt[i], i});
    string ans;
    int n = s.size();
    while (n--) {
        auto [ai, i] = q.top();
        q.pop();
        if (ans.empty() || ans.back() != i + 'a') {
            ans.push_back(i + 'a');
            cnt[i]--;
            q.push({cnt[i], i});
        } else {
            auto [bj, j] = q.top();
            q.pop();
            ans.push_back(j + 'a');
            cnt[j]--;
            q.push({cnt[i], i});
            q.push({cnt[j], j});
        }
    }
    cout << ans << '\n';
}