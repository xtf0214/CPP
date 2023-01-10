#include <bits/stdc++.h>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    n++;
    for (int i = 1; i <= 2 * n + 3; i++)
    {
        if (i == 1 || i == 2 * n + 3 || i == n + 2)
            for (int j = 1; j <= 3 * n + 8; j++)
                if (j == n + 2 + 1 || j == 2 * (n + 2) + 2)
                    cout << " ";
                else
                    cout << "#";
        else if (i < n + 2)
            for (int j = 1; j <= 3 * n + 8; j++)
                if (j == 1 || j == n + 2 || j == n + 2 + 2 || j == 3 * n + 8)
                    cout << "#";
                else
                    cout << " ";
        else
            for (int j = 1; j <= 3 * n + 8; j++)
                if (j == 1 || j == n + 2 || j == n + 2 + 2 || j == 2 * (n + 2) + 1 || j == 3 * n + 8)
                    cout << "#";
                else
                    cout << " ";
        cout << endl;
    }
    return 0;
}