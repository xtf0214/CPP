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
    int n;
    cin >> n;
    ouler(n);
    for (int i = 0; i < cnt; i++)
        cout << Prime[i] << " ";
    return 0;
}
