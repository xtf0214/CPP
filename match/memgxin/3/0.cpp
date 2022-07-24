#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int MAXN = 10000 + 5;
vector<pii> p;
int getPrimeNum(ll x)
{
    int res = 0;
    for (int i = 2; i * i <= x; i++)
        for (; x % i == 0; x /= i)
            res++;
    if (x > 1)
        res++;
    return res;
}
int main()
{
    cout << getPrimeNum(12);
    return 0;
}