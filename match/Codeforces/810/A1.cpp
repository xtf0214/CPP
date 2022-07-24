#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T, n, x;
    cin >> T;
    while (T--)
    {
        cin >> x;
        n = x;
        vector<int> a(n);
        for (int i = 0; i < a.size(); i++)
            a[i] = i + 1;
        if ((n - 1) & 1)
            n--;
        for (int i = 1; i < n; i++)
            a[i] = a[i] ^ 1;
        if ((x - 1) & 1)
            swap(a[x - 2], a[x - 1]);
        for (int i : a)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}