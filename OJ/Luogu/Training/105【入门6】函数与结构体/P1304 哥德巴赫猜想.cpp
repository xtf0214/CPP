#include <iostream>
using namespace std;
bool Prime(int x)
{
    if (x == 0 || x == 1)
        return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return true;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 4; i <= n; i += 2)
        for (int j = 2; j < i; j++)
            if (Prime(j))
                if (Prime(i - j))
                {
                    cout << i << "=" << j << "+" << i - j << endl;
                    break;
                }
    return 0;
}