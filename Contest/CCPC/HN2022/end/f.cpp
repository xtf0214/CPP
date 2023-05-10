#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define all(v) v.begin(), v.end()
#define print(v) for (int i = 0; i < v.size(); cout << v[i] << " \n"[i == v.size() - 1], ++i)

int main()
{
    int n, k;
    vi a;
    cin >> n;
    if (n == 2 || n == 4)
        return (cout << "-1", 0);
    else if (n & 1)
    {
        k = (n + 1) / 2;
        a.resize(k);
        iota(all(a), 1);
    }
    else
    {
        k = n / 2;
        a.resize(k);
        iota(all(a), 1);
        a[0] = 0;
    }
    cout << k << endl;
    print(a);
    return 0;
}