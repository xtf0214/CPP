#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10000 + 5;
int main()
{
    int vec[4][2]{{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
    for (auto [x, y] : vec)
    {
        cout << x << " " << y << endl;
    }

    return 0;
}