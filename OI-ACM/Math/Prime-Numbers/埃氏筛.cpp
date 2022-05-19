#include <iostream>
#include <cstring>
using namespace std;
const int MAX = 1000005;
int isPrime[MAX];
int Prime[MAX], cnt = 0;
void eratosthenes(int n)
{
    memset(isPrime, 1, sizeof(isPrime));
    isPrime[1] = 0;
    for (int i = 2; i * i <= n; i++)
        if (isPrime[i])
        {
            Prime[cnt++] = i;
            for (int j = 2 * i; j <= n; j += i)
                isPrime[j] = 0;
        }
}
int main()
{
    int n;
    cin >> n;
    eratosthenes(n);
    for (int i = 0; i < cnt; i++)
            cout << Prime[i] << " ";
    return 0;
}