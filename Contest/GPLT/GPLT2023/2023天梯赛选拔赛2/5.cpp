#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    int m = ceil(1.0 * y / x);
    cout << max(0, n - m);
}