/**
 * @file    :   调和平均
 * @author  :   Tanphoon
 * @date    :   2023/12/25 09:46
 * @version :   2023/12/25 09:46
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    double x = 0;
    for (int i = 0; i < n; i++) {
        double a;
        cin >> a;
        x += 1.0 / a;
    }
    printf("%.2lf\n", 1.0 / (x / n));
}