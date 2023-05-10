#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);

double A(double a, double b, double theta) { return a * b / 2 * atan(a / b * tan(theta)); }
void solve() {
    double a1, b1, a2, b2, ans;
    cin >> a1 >> b1 >> a2 >> b2;
    double sa = PI * a1 * b1, sb = PI * a2 * b2;
    if (a1 > a2 && b1 > b2) {
        ans = sa;
    } else if (a1 < a2 && b1 < b2) {
        ans = sb;
    } else {
        double alpha =
            atan(sqrt(-(a2 * a2 - a1 * a1) / (b2 * b2 - b1 * b1) * (b1 * b1 * b2 * b2) / (a1 * a1 * a2 * a2)));
        double cap = A(a2, b2, alpha) + (PI / 4 * a1 * b1 - A(a1, b1, alpha));
        cap *= 4;
        ans = sa + sb - cap;
    }
    printf("%.1lf\n", ans);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
