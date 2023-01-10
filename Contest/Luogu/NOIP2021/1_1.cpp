#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int S[10000005], n;
bool IsSeven(int x)
{
    while (x > 0)
    {
        if (x % 10 == 7)
            return true;
        x /= 10;
    }
    return false;
}
int main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
        S[i] = -1;
    for (int i = 7; i < n; i++)
    {
        if (S[i] != -1)
            continue;
        if (IsSeven(i))
            for (int j = i; j < n; j += i)
                S[j] = 1;
        else
            S[i] = 0;
    }
    for (int i = 1; i < n; i++)
        if (S[i] == 1)
            printf("%d ", i);
}