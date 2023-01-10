#include <iostream>
using namespace std;
int a[1000010];
int n;
bool search(int x)
{
    int left = 0, right = n, mid;
    while (left < right)
    {
        mid = (left + right) / 2;
        if (x == a[mid])
            return true;
        else if (x < a[mid])
            right = mid;
        else
            left = mid + 1;
    }
    return false;
}
int main()
{
    int q, b;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> b;
        s += search(b) ? "Y" : "N";
    }
    cout << s;
    return 0;
}