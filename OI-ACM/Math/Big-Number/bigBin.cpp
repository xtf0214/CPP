#include <bits/stdc++.h>
using namespace std;

using BigInt = string;
#define ctoi(s) for (int i = 0; i < s.size(); s[i++] -= '0')
#define itoc(s) for (int i = 0; i < s.size(); s[i++] += '0')
BigInt half(BigInt a)
{
    // ctoi(a) to clac  // itoc(s) to print
    if (a.size() == 1 && (a[0] == 1 || a[0] == 0))
        return {0};
    BigInt s;
    int n = a.size();
    if (a[0] / 2) // a[0] >= 2
        s.push_back(a[0] / 2), a[0] %= 2;
    for (int i = 1; i < n; i++)
    {
        s.push_back((a[i - 1] * 10 + a[i]) / 2);
        a[i] = (a[i - 1] * 10 + a[i]) % 2;
    }
    return s;
}
BigInt reverseBin(BigInt a)
{
    // ctoi(a) to clac  // itoc(r) to print
    BigInt r;
    for (; a != BigInt{0}; a = half(a))
        r.push_back(a.back() & 1);
    if (r.empty())
        r = {0};
    return r;
}
int main()
{
    BigInt a, s;
    cin >> a;
    ctoi(a);
    s = reverseBin(a);
    itoc(s);
    cout << s;
    return 0;
}