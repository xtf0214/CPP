#include<bits/stdc++.h>
using namespace std;
int n, r, score, combo;
double Ox[1000005], Oy[1000005], Cx, Cy;
int main()
{
    cin >> n >> r;
    for (int i = 0; i < n; i++)
        scanf("%lf %lf", &Ox[i], &Oy[i]);
    for (int i = 0; i < n; i++)
    {
        scanf("%lf %lf", &Cx, &Cy);
        double d = sqrt((Ox[i] - Cx) * (Ox[i] - Cx) + (Oy[i] - Cy) * (Oy[i] - Cy));
        if (d >= r)
            combo = 0;
        else
        {
            combo++;
            int k = combo / 100; //取百位上的数
            if (k >= 4)
                k = 4; 
            if (d < 0.2 * r)
                score += 300 + k * 3; //score = 300(1+k%) = 300 + 3 * k
            else if (0.2 * r <= d && d < 0.5 * r)
                score += 200 + k * 2;
            else if (0.5 * r <= d && d < r)
                score += 100 + k;
        }
    }
    cout << score;
    return 0;
}