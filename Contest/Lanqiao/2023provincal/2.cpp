#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define db(x) cout << #x << " = " << x << endl
const double eps = 1e-3;
double ans = 11625907.5798;
int N = 23333333;

int main() {
    // ans = 1.3083;
    // N = 3;
    for (ll x = 0; x < N; x++) {
        double t = -(x * x * log2(1.0 * x / N) + (N - x) * (N - x) * log2(1.0 * (N - x) / N)) / N;
        if (abs(ans - t) < eps) {
            db(x);
            printf("%.10lf\n", ans);
        }
    }
}
