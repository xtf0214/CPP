#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10000 + 5;
int main()
{
    int n = 8;
    vector<int> arr(n, 1);
    for (int i = 1; i <= n; i++)
    {
        int opt, l, r, d;
        // cin >> opt;
        // if (opt == 1)
        //     cin >> d, seg.update(i, d - 1);
        // else if (opt == 2)
        //     cin >> l >> r, seg.update(l, r, 1);
        cin >> opt >> l >> r;
        if (opt == 0)
        {
            cin >> d;
            for (int i = l; i <= r; i++)
                arr[i - 1] = d;
            // for (int i : arr)
                // cout << i << " ";
            // cout << endl;
        }
        else
        {
            int res = 0;
            for (int i = l; i <= r; i++)
                res *= arr[i - 1];
            cout << res << endl;
        }
    }
}