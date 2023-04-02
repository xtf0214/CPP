#include <bits/stdc++.h>
using namespace std;
const int N = 20000 + 5;
int a[N];
int main() {
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> a[n + i];
    sort(a, a + n + m);
    int l = unique(a, a + n + m) - a;
    for (int i = 0; i < l; i++)
        cout << a[i] << " ";
    return 0;
}