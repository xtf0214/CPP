#include <iostream>
using namespace std;
int a[10000], d[10000];
int n, p, q;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> p;
    for (int i = 0, a, b, v; i < p; i++)
    {
        cin >> a >> b >> v;
        a--, b--;
        d[a] += v;
        d[b + 1] -= v;
    }
    for (int i = 1; i < n; i++)
        d[i] += d[i - 1];
    cin >> q;
    for (int i = 0, t; i < q; i++)
    {
        cin >> t;
        t--;
        cout << a[t] + d[t] << endl;
    }
    return 0;
}