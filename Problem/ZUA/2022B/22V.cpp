// 1038 Problem  V	鸡兔同笼问题（第四讲）
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    int flag = 1;
    for (int i = 1; i <= n; i++) {
        int j = n - i;
        if (i * 2 + j * 4 == m) {
            cout << i << " " << j;
            flag = 0;
        }
    }
    if (flag) {
        cout << "No answer";
    }
    return 0;
}