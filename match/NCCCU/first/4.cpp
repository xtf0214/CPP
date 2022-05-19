#include <iostream>
using namespace std;
int A[1005][1005];
int main()
{
    int n, k, min = 1000;
    cin >> n >> k;
    for (int y = 0; y < n; y++)
        for (int x = 0; x < n; x++)
            cin >> A[y][x];
    for (int y = 0; y < n - k + 1; y++)
        for (int x = 0; x < n - k + 1; x++)
        {
            int s = 0;
            for (int i = 0; i < k; i++)
                for (int j = 0; j < k; j++)
                    s += A[y + i][x + j];
            min = s < min ? s : min;
        }
    cout << min;
    return 0;
}
/* 5 2
2 2 1 1 1
1 2 1 5 6
6 1 1 4 5
2 6 1 1 1
1 1 1 1 1 */