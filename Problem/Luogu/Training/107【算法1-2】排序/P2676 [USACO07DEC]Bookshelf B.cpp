#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n, H[20005] = {0}, b, s = 0, t = 0;
    cin >> n >> b;
    for (int i = 0; i < n; i++)
        cin >> H[i];
    sort(H, H + n, greater<int>());
    while (s < b)
        s += H[t++];
    cout << t << endl;
    return 0;
}
