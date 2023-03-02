/**
 * @file    :   7-29 统计字符出现的次数
 * @author  :   Tanphoon
 * @date    :   2023/03/02 18:38
 * @version :   2023/03/02 18:38
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 128;

int main() {
    string s;
    while (getline(cin, s)) {
        int cnt[N] = {0};
        for (char ch : s)
            cnt[ch]++;
        vector<char> ans;

        for (int ch = 0; ch < N; ch++)
            if (isalpha(ch) && cnt[ch] > 0)
                ans.push_back(ch);
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << "--" << cnt[ans[i]] << " \n"[(i + 1) % 10 == 0 || i + 1 == ans.size()];
    }
}