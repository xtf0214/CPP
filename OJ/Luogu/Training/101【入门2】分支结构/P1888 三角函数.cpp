#include <iostream>
using namespace std;
int gcd(int m, int n)
{
    return n == 0 ? m : gcd(n, m % n);
}
int main()
{
    int p[4], temp, i, j;
    float m, n;
    for (i = 0; i < 3; i++)
        cin >> p[i];
    for (i = 2; i >= 1; i--)
        for (j = 0; j < i; j++)
            if (p[j] > p[j + 1])
                swap(p[j], p[j + 1]);
    int k = gcd(p[0], p[2]);
    cout << p[0] / k << "/" << p[2] / k;
}