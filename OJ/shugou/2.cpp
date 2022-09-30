#include <iostream>
using namespace std;
int main()
{
    int *a = new int{5};
    cout << a[0] << " ";
    int *t = a + 1;
    t = new int{6};
    a[1] = 6;
    cout << a[1] << " ";
    return 0;
}