#include <iostream>
#include <string>
using namespace std;
int main()
{
    char c;
    string str;
    int n;
    cin >> c >> n;
    getchar();
    int a[n][n];
    for (int y = 0; y < n; y++)
    {
        getline(cin, str);
        for (int x = 0; x < n; x++)
            a[y][x] = (str[x] == ' ') ? 0 : 1;
    }
    bool same = true;
    for (int y = 0; y < n; y++)
        for (int x = 0; x < n; x++)
            if (a[y][x] != a[n - 1 - y][n - 1 - x])
            {
                same = false;
                break;
            }
    if (same)
        cout << "bu yong dao le" << endl;
    for (int y = n - 1; y >= 0; y--)
    {
        for (int x = n - 1; x >= 0; x--)
            if (a[y][x] == 0)
                cout << " ";
            else
                cout << c;
        cout << endl;
    }
    return 0;
}