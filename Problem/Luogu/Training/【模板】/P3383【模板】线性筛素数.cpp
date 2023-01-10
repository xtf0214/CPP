#include <iostream>
#include <cstring>
using namespace std;
const int MAX = 100000005;
bool isPrime[MAX];
int Prime[MAX], cnt = 0;
void ouler(int n)
{
    memset(isPrime, 1, sizeof(isPrime));
    isPrime[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i])
            Prime[cnt++] = i;
        for (int j = 0; j < cnt && i * Prime[j] <= n; j++)
        {
            isPrime[i * Prime[j]] = 0;
            if (i % Prime[j] == 0)
                break;
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    int n, m, x;
    cin >> n >> m;
    ouler(n);
    while (m--)
    {
        cin >> x;
        cout << Prime[x - 1] << endl;
    }
    return 0;
}
