#include <bits/stdc++.h>
using namespace std;

int gcd(int m, int n) { return n ? gcd(n, m % n) : m; }
void solve()
{
    int n, m;
    cin >> m >> n;
    cout << m / gcd(m, n) * n << endl;
}
int main()
{
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}