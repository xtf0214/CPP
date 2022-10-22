#include <bits/stdc++.h>
using namespace std;
class int128
{
    int len, a[1050]; // 2^n: log(10,2)*n ≈ n/3  fib(n): -log(10,5)/2+n*log(10,(1+√5)/2) ≈ n/5

public:
    int128(int x = 0)
    {
        memset(a, 0, sizeof(a));
        for (len = 1; x; len++)
            a[len] = x % 10, x /= 10;
        len--;
    }
    int &operator[](int i) { return a[i]; }
    void flatten(int l)
    {
        len = l;
        for (int i = 1; i <= len; i++)
            a[i + 1] += a[i] / 10, a[i] %= 10;
        while (!a[len])
            len--;
    }
    friend ostream &operator<<(ostream &out, const int128 &t)
    {
        for (int i = max(t.len, 1); i >= 1; i--)
            out << t.a[i];
        return out;
    }
    int128 operator+(int128 b)
    {
        int128 c;
        c.len = max(len, b.len);
        for (int i = 1; i <= c.len; i++)
            c[i] += a[i] + b[i];
        c.flatten(c.len + 1);
        return c;
    }
    int128 operator*(int b)
    {
        int128 c;
        c.len = len;
        for (int i = 1; i <= c.len; i++)
            c[i] = a[i] * b;
        c.flatten(c.len + 11);
        return c;
    }
};
int128 f[5005];
int main()
{
    int n;
    cin >> n;
    f[1] = int128(1);
    f[2] = int128(2);
    for (int i = 3; i <= n; i++)
        f[i] = f[i - 1] + f[i - 2];
    cout << f[n];
    return 0;
}
