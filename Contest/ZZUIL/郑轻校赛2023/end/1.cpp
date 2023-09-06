/** 
 * @file    :   1 计算括号对
 * @author  :   Tanphoon 
 * @date    :   2023/09/06 15:10
 * @version :   2023/09/06 15:10
 * @link    :   http://acm.zzuli.edu.cn/problem.php?id=3031
 */
#include <bits/stdc++.h>
using namespace std;

using Poly = vector<int>;
using Complex = complex<double>;
const double PI = acos(-1);
int rev[1 << 22];
void FFT(Complex a[], int n, int inv) {
    for (int i = 0; i < n; ++i)
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << __lg(n >> 1));
    for (int i = 0; i < n; ++i)
        if (i < rev[i])
            swap(a[i], a[rev[i]]);
    for (int i = 2; i <= n; i <<= 1) {
        Complex wn(cos(2 * PI / i), inv * sin(2 * PI / i));
        for (int j = 0; j < n; j += i) {
            Complex w0(1, 0);
            for (int k = j; k < j + i / 2; ++k, w0 *= wn) {
                Complex x = a[k], y = w0 * a[k + i / 2];
                a[k] = x + y;
                a[k + i / 2] = x - y;
            }
        }
    }
    if (inv == -1)
        for (int i = 0; i < n; i++)
            a[i] /= n;
}
Poly operator*(Poly a, Poly b) {
    int n = a.size() + b.size() - 1;
    vector<Complex> c(2 << __lg(n - 1));
    for (int i = 0; i < a.size(); i++)
        c[i].real(a[i]);
    for (int i = 0; i < b.size(); i++)
        c[i].imag(b[i]);
    FFT(c.data(), c.size(), 1);
    for (int i = 0; i < c.size(); i++)
        c[i] = c[i] * c[i];
    FFT(c.data(), c.size(), -1);
    Poly s(n);
    for (int i = 0; i < n; i++)
        s[i] = (int)(c[i].imag() / 2 + 0.5);
    return s;
}

int main() {
    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;
    Poly a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) 
        if (s[i] == '(')
            a[n - i] = 1; // a[-i] = 1
        else
            b[i] = 1;
    Poly ans = a * b;
    for (int i = 1; i < n; i++) 
        cout << ans[i + n] << " \n"[i == n];
}