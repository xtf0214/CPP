#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    vector<string> ans;
    cin >> n >> m;
    cin.get();
    while (n--) {
        string s;
        getline(cin, s);
        if (s.find("qiandao") != -1 || s.find("easy") != -1) // 存在"qiandao"或者"easy"的题目，吉老师会跳过
            continue;
        ans.push_back(s);
    }
    if (ans.size() <= m)
        cout << "Wo AK le";
    else
        cout << ans[m];
    return 0;
}