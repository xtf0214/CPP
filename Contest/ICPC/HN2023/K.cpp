/** 
 * @file    :   K
 * @author  :   Tanphoon 
 * @date    :   2023/05/21 20:35
 * @version :   2023/05/21 20:35
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int a[N];
int main() {
    int n;
    cin >> n;
    long long s1 = 0, s2 = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] >= 0)
            s2 += a[i];
        else
            s1 += a[i];
    }
    // -3 -2 -1 1 2 3
    if (s1 == 0 && s2 != 0) { // 全正
        int mn = *min_element(a, a + n);
        cout << mn * (s2 - mn);
    } else if (s1 != 0 && s2 == 0) { // 全负
        int mx = *max_element(a, a + n);
        cout << mx * (s1 - mx);
    } else {
        cout << s1 * s2;
    }
    return 0;
}
