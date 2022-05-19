#include <bits/stdc++.h>
using namespace std;
bool solve(int x)
{
    vector<int> a;
    while (x)
        a.push_back(x % 10), x /= 10;
    for (int j = 1; j < a.size(); j++)
        if (a[j] == a[j - 1])
            return false;
    return true;
}
int main()
{
    int m, n;
    cin >> n >> m;
    for (int i = n; i <= m; i++)
        if (solve(i))
            cout << i << " ";
    return 0;
}