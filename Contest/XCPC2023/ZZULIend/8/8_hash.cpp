// 301021 *郑州大学——王牌特工队(邱宇\张东方\刘玥含)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, flag[1010], len[1010], ans;
ll f[1010][1010];
string s[1010];
ll B = 233, M = 1e9 + 7;
map<ll, int> o;
void work(int i) {
    f[i][0] = s[i][0];
    for (int j = 1; j < len[i]; j++)
        f[i][j] = (f[i][j - 1] * B + s[i][j]) % M;
}
int main() {
    // 	freopen("1.in","r",stdin);
    cin >> n;
    getline(cin, s[0]);
    for (int i = 1; i <= n; i++)
        getline(cin, s[i]);
    for (int i = 1; i <= n; i++) {
        if (s[i].substr(0, 7) == "what's ") {
            s[i] = s[i].substr(7, s[i].length() - 7);
            flag[i] = 1;
            len[i] = s[i].length();
            work(i);
        } else {
            len[i] = s[i].length();
            work(i);
            int pos = 0;
            for (int j = 1; j < i; j++) {
                //				cout<<"??";
                if (flag[j] && len[i] >= len[j] && f[j][len[j] - 1] == f[i][len[j] - 1] && len[j] > len[pos] &&
                    o[f[j][len[j] - 1]] == 0)
                    pos = j;
            }
            if (pos != 0) {
                ans++;
                flag[pos] = 0;
                o[f[pos][len[pos] - 1]] = 1;
            }
        }
    }
    cout << ans;
}