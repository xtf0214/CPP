#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N];
long long pr[N], sum;
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pr[i] = pr[i - 1] + a[i];
    }
    for (int i = 2; i <= n; i++)
        sum += a[i] * pr[i - 1];
    cout << sum;
    return 0;
}