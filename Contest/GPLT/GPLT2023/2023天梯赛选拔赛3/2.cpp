#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cout << max({i, 2 * (i - 1), 2 * (n - i)});
}