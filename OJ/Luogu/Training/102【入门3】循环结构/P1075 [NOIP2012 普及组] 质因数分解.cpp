#include <iostream>
using namespace std;
int main()
{
    long long x;
    cin >> x;
    for (int i = 2; i <= x; i++) //当i->INF时,i-sqrt(i) >> sqrt(i) , 故从2开始遍历能节省时间
        if (x % i == 0)
        {
            cout << x / i << endl;
            return 0;
        }
}