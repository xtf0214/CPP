#include <iostream>
using namespace std;
int a[100], h, s;
int main()
{
    int i;
    for (i = 0; i < 10; i++)
        cin >> a[i];
    cin >> h;
    for (i = 0; i < 10; i++)
        if (h + 30 >= a[i])
            s++;
    cout << s;
    return 0;
}
