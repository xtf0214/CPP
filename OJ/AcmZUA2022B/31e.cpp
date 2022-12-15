// 1047 Problem  e	Let the Balloon Rise（第六讲）
#include <bits/stdc++.h>
using namespace std;

void solve(int n) {
    map<string, int> color;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        ++color[s];
    }
    auto ans = color.begin();
    for (auto it = color.begin(); it != color.end(); it++)
        if (ans->second < it->second)
            ans = it;
    cout << ans->first << endl;
}
int main() {
    int n;
    while (cin >> n && n)
        solve(n);
    return 0;
}