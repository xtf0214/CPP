// 1037 Problem  U	最大乘积问题（第四讲）
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int max = -1, num;
    for (int i = 0; i < n; i++) {
        num = 1;
        for (int j = i; j < n; j++) {
            num = num * a[j];
            if (num > max)
                max = num;
        }
    }
    if (max <= 0)
        cout << "0";
    else
        cout << max;
    return 0;
}