#include <iostream>
#include <algorithm>
using namespace std;
int A[1005], B[1005]; //A[n],B[n+1]
int l, m, n;
int main()
{
    cin >> l >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        if (i)
            B[i] = A[i] - A[i - 1];
    }
    B[0] = A[0];
    B[n] = l - A[n - 1];
    sort(B, B + n + 1);

    int step, num, tempp;
    for (int i = 0; i <= n; i++)
    {
        step = B[i];
        num = m;
        for (int j = i + 1; j <= n; j++)
        {
            tempp = B[j];
            while (tempp > step)
            {
                tempp -= step;
                --num;
                if (num == 0)
                    break;
            }
            if (num == 0 && j == n)
            {
                cout << step << endl;
                return 0;
            }
            if (num == 0)
                break;
        }
    }
    return 0;
}