// 	1036 Problem  T	分数拆分问题（第四讲）
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    while (cin >> n) {
        int count = 0;
        for (int y = n + 1; y <= 2 * n; y++) {
            int x = (y * n) / (y - n);
            if ((x * n) % (x - n) == 0)
                count++;
        }
        cout << count << endl;
        for (int y = n + 1; y <= 2 * n; y++) {
            int x = (y * n) / (y - n);
            if ((x * n) % (x - n) == 0) {
                y = (n * x) / (x - n);
                cout << "1/" << n << " = "
                     << "1/" << x << " +"
                     << " 1/" << y << endl;
            }
        }
    }
    return 0;
}