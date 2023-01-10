// P5710 【深基3.例2】数的性质
#include <iostream>
using namespace std;
int main()
{
    int x;
    cin >> x;
    int ans1 = x % 2 == 0;
    int ans2 = 4 < x && x <= 12 ? 1 : 0;
    printf("%d %d %d %d", ans1 && ans2, ans1 || ans2, ans1 ^ ans2, !(ans1 || ans2));
    return 0;
}