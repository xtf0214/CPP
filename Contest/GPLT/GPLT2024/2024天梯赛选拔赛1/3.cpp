/** 
 * @file    :   判断素数
 * @author  :   Tanphoon 
 * @date    :   2023/12/25 09:50
 * @version :   2023/12/25 09:50
 */
#include <bits/stdc++.h>
using namespace std;

bool isPrime(long long x) {
    for (long long i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return x > 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        long long x;
        cin >> x;
        cout << (isPrime(x) ? "Yes" : "No") << '\n';
    }
}
