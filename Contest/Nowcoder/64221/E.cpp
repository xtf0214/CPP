/** 
 * @file    :   E
 * @author  :   Tanphoon 
 * @date    :   2023/08/30 21:16
 * @version :   2023/08/30 21:16
 * @link    :   https://ac.nowcoder.com/acm/contest/64221/E
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const double PI = acos(-1);
const double eps = 1e-8;

double toRad(double theta) { return theta * PI / 180; }
int main() {
    int n;
    cin >> n;
    double x = 0, y = n * sin(toRad(54)) / sin(toRad(36));
    double d = x * sin(toRad(-72)) + y * cos(toRad(-72));
    for (int i = 1; i <= 5; i++) {
        double nx = x * cos(toRad(72 * -i)) - y * sin(toRad(72 * -i));
        double ny = x * sin(toRad(72 * -i)) + y * cos(toRad(72 * -i)) - d;
        if (abs(nx - 0) < eps)
            nx = 0;
        if (abs(ny - 0) < eps)
            ny = 0;
        printf("%c: %.2lf %.2lf\n", 'A' + i - 1, nx, ny);
    }
    return 0;
}