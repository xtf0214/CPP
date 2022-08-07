#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10000 + 5;
int main()
{
    int T;
    bool used[26];
    string s;
    cin >> T;
    while (T--)
    {
        cin >> s;
        int cnt = 0;
        memset(used, false, sizeof(used));
        for (char i : s)
            if (!used[i - 'a'])
            {
                cnt++;
                if (cnt % 3 == 1 && cnt != 1)
                    memset(used, false, sizeof(used));
                used[i - 'a'] = true;
            }
        cout << int(ceil(cnt / 3.0)) << endl;
    }
    return 0;
}