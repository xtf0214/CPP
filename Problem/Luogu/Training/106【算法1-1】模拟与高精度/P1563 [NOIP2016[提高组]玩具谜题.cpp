#include <iostream>
#include <string>
using namespace std;
struct
{
    int face;
    string job;
} A[100001];
int main()
{
    int m, n, t = 0, turn, round;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> A[i].face >> A[i].job;
    for (int i = 0; i < m; i++)
    {
        cin >> turn >> round;
        if (A[t].face == turn)
        {
            t -= round;
            if (t < 0)
                t += n;
        }
        else
        {
            t += round;
            if (t >= 0)
                t -= n;
        }
    }
    cout << A[t].job << endl;
    return 0;
}