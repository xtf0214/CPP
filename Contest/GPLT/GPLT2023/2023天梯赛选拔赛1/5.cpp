#include <iostream>
using namespace std;
int main() {
    int i, k = 0, s = 0, x; // i表示月份，k表示每月剩余的钱，s表示存款，x表示预算
    for (i = 1; i <= 12; i++) {
        cin >> x;
        if (k + 300 - x >= 0) {
            s += (k + 300 - x) / 100 * 100;
            k = (k + 300 - x) % 100;
        } else {
            cout << "-" << i;
            return 0;
        }
    }
    cout << s * 1.2 + k;
    return 0;
}