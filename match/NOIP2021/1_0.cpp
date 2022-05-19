#include <cstdio>
#include <cstring>
using namespace std;
int S[20000005];
int IsSeven(int x)
{
    if (S[x] != -1)
        return S[x];
    int t = x;
    while (t > 0)
    {
        if (t % 10 == 7)
            return S[x] = 1;
        t /= 10;
    }
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
        {
            if (IsSeven(i))
                return S[i] = 1;
            if (IsSeven(x / i))
                return S[x / i] = 1;
        }
    return S[x] = 0;
}
int find(int x)
{
    while (true)
    {
        if (!IsSeven(x))
            return x;
        x++;
    }
}
int main()
{
    int n, x;
    memset(S, -1, sizeof(S));
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        if (IsSeven(x))
        {
            printf("-1\n");
            continue;
        }
        printf("%d\n", find(x + 1));
    }
    return 0;
}
