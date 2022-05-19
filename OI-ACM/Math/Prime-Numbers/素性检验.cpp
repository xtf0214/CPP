#include <iostream>
using namespace std;
bool Prime(int x)
{
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return x != 1;
}
int main()
{
    int n,cnt=0;
    cin >> n;
    for (int i = 1; i < n; i+=2)
        if (Prime(i))
            cnt++;
    cout<<cnt;
    return 0;
}