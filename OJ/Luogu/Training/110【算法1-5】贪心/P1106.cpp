// P1106 删数问题
// https://www.luogu.com.cn/problem/P1106
#include <iostream>
using namespace std;
string s;
int n, a[251];
int main() {
    cin >> s;
    cin >> n;
    int len = s.length();
    for (int i = 0; i < len; i++)
        a[i] = s[i] - '0';
    for (int i = 1; i <= n; i++)
        for (int i = 0; i < len; i++)
            if (a[i] > a[i + 1]) {
                copy(a + i + 1, a + len + 1, a + i);
                len--;
                break;
            }
    int l = 0;
    for (int i = 0; a[i] == 0 && l < len - 1; i++)
        l++;
    for (int i = l; i < len; i++)
        printf("%d", a[i]);
    return 0;
}