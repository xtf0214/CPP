//	1124 Problem  l	雷达侦测目标
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, count = 0;
    double r;
    cin >> n >> r;
    for (int i = 0; i < n; i++) {
        int j, k;
        cin >> j >> k;
        if (hypot(j, k) < r)
            count++;
    }
    cout << count;
    return 0;
}