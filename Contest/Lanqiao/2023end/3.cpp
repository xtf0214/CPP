#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

#ifdef _LQDEBUG
#define db(x) cout << #x << " = " << x << endl
#define cin fin
fstream fin("C:\\Users\\Administrator\\Desktop\\input\\3.txt");
#endif

signed main() {
    int T;
    cin >> T;
    int mx = INT_MAX, mn = -INT_MAX;
    while (T--) {
        int a, b;
        cin >> a >> b;
        int r = a / b;
        int i;
        for (i = 1; a / (r + i) == b; i++)
            ;
        mx = min(mx, (r + i - 1));

        for (i = 1; a / (r - i) == b; i++)
            ;
        mn = max(mn, (r - i + 1));
    }
    cout << mn << " " << mx;
    return 0;
}
