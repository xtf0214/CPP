#include <iostream>
using namespace std;
int main()
{
    int n1, n2, cnt = 0;
    cin >> n1 >> n2;
    while (n1 != 0 && n2 != 0)
    {
        if (n1 >= n2)
        {
            n1 -= n2;
            cnt++;
        }
        else
        {
            n2 -= n1;
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}