/**
 * @file    :   H
 * @author  :   Tanphoon
 * @date    :   2024/05/08 03:43
 * @version :   2024/05/08 03:43
 * @link    :   https://codeforces.com/gym/102803/problem/H
 */
#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
int reduceFraction(ull &a, ull &b) {
    ull g = gcd(a, b);
    a /= g, b /= g;
}
ull g3(ull x) {
    ull a = x, b = x + 1, c = x, d = x + 1;
    ull t = 4;
    reduceFraction(a, t);
    reduceFraction(b, t);
    reduceFraction(c, t);
    reduceFraction(d, t);
    return a * b * c * d;
}
ull g2(ull x) {
    ull a = x, b = x + 1, c = 2 * x + 1;
    ull t = 6;
    reduceFraction(a, t);
    reduceFraction(b, t);
    reduceFraction(c, t);
    return a * b * c;
}
ull g1(ull x) {
    ull a = x, b = x + 1;
    ull t = 2;
    reduceFraction(a, t);
    reduceFraction(b, t);
    return a * b;
}
ull g0(ull x) { return x; }
vector<function<ull(ull)>> fn = {g0, g1, g2, g3};
ull H(ull n, int k) {
    ull res = 0;
    auto f = fn[k];
    for (ull l = 1, r = 1; l <= n; l = r + 1) {
        ull d = n / l;
        r = n / d;
        res += (f(r) - f(l - 1)) * d;
    }
    return res;
}
int main() {
    ull a, b, n;
    cin >> a >> b >> n;
    cout << ull(H(n, a) ^ H(n, b)) << '\n';
}
