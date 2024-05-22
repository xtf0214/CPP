#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    string s;
    cin >> s;
    int x;
    cin >> x;
    int n = s.size();
    if (s == "0" && x == 1) {
        cout << -1 << '\n';
        return 0;
    }
    if (n < x) {
        cout << -1 << '\n';
        return 0;
    } else if (n == x) {
        for (int i = 0; i < n; i++)
            s[i] = '1' - s[i] + '0';
        int idx = s.find('1');
        if (idx == -1)
            cout << '0' << '\n';
        else
            cout << s.substr(s.find('1')) << '\n';
        return 0;
    } else if (x == 0) {
        cout << s << '\n';
        return 0;
    } 
    string ans(n, '0');
    reverse(s.begin(), s.end());
    for (int i = x - 1; i < n; i++) {
        if (s[i] == '1') {
            ans[i] = '0';
            for (int j = i + 1; j < n; j++)
                ans[j] = s[j];
            int cnt = i - (x - 1);
            // cout<<cnt<<'\n';
            for (int j = x; j < i; j++)
                ans[j] = '1';
            for (int j = x - 1; j >= 0; j--)
                if (s[j] == '0')
                    ans[j] = '1';
                else {
                    if (cnt)
                        ans[j] = '1', cnt--;
                }
            break;
        }
    }
    reverse(ans.begin(), ans.end());

    int idx = ans.find('1');
    if (idx == -1)
        cout << '0' << '\n';
    else
        cout << ans.substr(ans.find('1')) << '\n';
}