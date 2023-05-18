#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e6 + 5;
int isPrime[N];
int Prime[N], cnt = 0;
void eratosthenes(int n) {
    memset(isPrime, 1, sizeof(isPrime));
    isPrime[1] = false;
    for (int i = 2; i <= n; i++)
        if (isPrime[i]) {
            Prime[cnt++] = i;
            for (int j = 2 * i; j <= n; j += i)
                isPrime[j] = true;
        }
}
int main() {
    int n;
    cin >> n;
    eratosthenes(n);
    for (int i = 0; i < cnt; i++)
        cout << Prime[i] << " ";
    return 0;
}