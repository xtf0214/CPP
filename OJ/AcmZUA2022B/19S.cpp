// 1035 Problem  S	除法问题（第四讲）
#include <bits/stdc++.h>
using namespace std;
int main() {
    long n, k, count = 0;
    cin >> n;
    for (int i = 1234; i <= 98765 / n; ++i) {
        int arr[10] = {0};
        int tmpk = i * n, tmpi = i;
        while (tmpk) {
            arr[tmpk % 10]++;
            tmpk /= 10;
        }
        while (tmpi) {
            arr[tmpi % 10]++;
            tmpi /= 10;
        }
        int flag = 0;
        for (int i = 1; i < 10; ++i) {
            if (arr[i] != 1) {
                flag = 1;
                break;
            }
        }
        if (!flag) {
            if (arr[0] == 0)
                cout << i * n << " / 0" << i << " = " << n << endl;
            else
                cout << i * n << " / " << i << " = " << n << endl;
        }
    }
    return 0;
}