#include <iostream>
#include <cstring>
#include <string>
using std::ostream;
using std::string;
using std::max;
using std::to_string;

using typebit = int;
using typelen = long long;
class BigNum
{
    // log(10,2) ≈ 0.30102999566398119521373889472449
    // log(2,10) ≈ 3.3219280948873623478703194294894
    // 2^n figure: log(10,2)*n ≈ n/3
    // fib(n) figure: -log(10,5)/2+n*log(10,(1+√5)/2) ≈ n/5
    typelen len;
    typebit* num;

public:
    BigNum(long long x = 0)
    {
        num = new typebit[1000000]{ 0 };
        len = 1;
        for (; x; len++)
            num[len] = x % 10, x /= 10;
        len--;
    }
    typebit& operator[](typelen i) { return num[i]; }
    void flatten(typelen l)
    {
        len = l;
        for (typelen i = 1; i <= len; i++)
            num[i + 1] += num[i] / 10, num[i] %= 10;
        while (!num[len])
            len--;
    }
    friend ostream& operator<<(ostream& out, const BigNum& t)
    {
        if (t.len == 0)
            return (out << 0);
        for (typelen i = t.len; i >= 1; i--)
            out << t.num[i];
        return out;
    }
    BigNum operator+(BigNum b)
    {
        BigNum c;
        c.len = max(len, b.len);
        for (typelen i = 1; i <= c.len; i++)
            c[i] += num[i] + b[i];
        c.flatten(c.len + 1);
        return c;
    }
    BigNum operator*(typebit b)
    {
        BigNum c;
        c.len = len;
        for (typelen i = 1; i <= c.len; i++)
            c[i] = num[i] * b;
        c.flatten(c.len + 11);
        return c;
    }
    BigNum operator++()
    {
        num[1] += 1;
        flatten(len + 1);
        return *this;
    }
    void operator*=(typebit b)
    {
        for (typelen i = 1; i <= len; i++)
            num[i] *= b;
        flatten(len + 11);
    }
    string Enotation()
    {
        string s;
        s += to_string(num[len]) + '.';
        for (int i = 1; i < 10; i++)
            s += to_string(num[len - i]);
        s += 'e' + to_string(len - 1);
        return s;
    }
};