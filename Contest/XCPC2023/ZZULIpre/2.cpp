#include <bits/stdc++.h>
using namespace std;

const double pi = acos(-1);

int main() {
    int t;
    cin >> t;
    while (t--) {
        double n, x;
        cin >> n >> x;
        double ans = pow(n, pi);
        cout << fixed << setprecision(x) << ans << endl;
    }
    return 0;
}