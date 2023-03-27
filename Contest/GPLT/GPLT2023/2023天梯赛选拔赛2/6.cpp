#include <bits/stdc++.h>
using namespace std;

int main() {
    char c;
    int n;
    cin >> c >> n;
    for (int i = 1; i <= n; i++)
        cout << string(n - i, ' ') << string(2 * i - 1, c) << endl;
}