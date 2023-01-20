/**
 * @file    :   E
 * @author  :   Tanphoon
 * @date    :   2023/01/20 17:41
 * @version :   2023/01/20 17:41
 * @link    :   https://ac.nowcoder.com/acm/contest/46811/E
 */
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define x first
#define y second

template <typename T> pair<T, T> operator+(const pair<T, T> &a, const pair<T, T> &b) { return {a.x + b.x, a.y + b.y}; }
template <typename T> pair<T, T> operator-(const pair<T, T> &a, const pair<T, T> &b) { return {a.x - b.x, a.y - b.y}; }

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    pii A, B, C;
    cin >> A.x >> A.y >> B.x >> B.y;
    pii v1 = B - A;
    pair<double, double> v2 = {(v1.x - v1.y) / 2.0, (v1.x + v1.y) / 2.0};
    if (v2.x == int(v2.x) && v2.y == int(v2.y)) {
        pii v3 = {int(v2.x), int(v2.y)};
        C = A + v3; 
        cout << C.x << " " << C.y << endl;
    } else {
        cout << "No Answer!";
    }
    return 0;
}