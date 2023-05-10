#include <bits/stdc++.h>
using namespace std;

long long n, sum;

int main() {
    cin >> n;
    sum = (n + 1) * n / 2;
    sum -= n - 1;
    cout << sum <<endl;
    return 0;
}