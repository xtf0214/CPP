#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int MAXN = 10000 + 5;

struct Time
{
    int month[13]{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int y = 1, m = 1, d = 1;
    Time(int _y, int _m, int _d) : y(_y), m(_m), d(_d) { month[2] = (y % 400 == 0 || y % 4 == 0 && y % 100 != 0) ? 29 : 28; }
    pii get() { return {m, d}; }
    pii add()
    {
        d++;
        if (d > month[m])
        {
            d = 1, m++;
            if (m > 12)
            {
                m = 1, y++;
                month[2] = (y % 400 == 0 || y % 4 == 0 && y % 100 != 0) ? 29 : 28;
            }
        }
        return {m, d};
    }
};
void solve()
{
    int y, m, d, n, cnt = 0;
    scanf("%d-%d-%d", &y, &m, &d);
    Time time(y, m, d);
    scanf("%d", &n);
    int t1 = 0, t2 = 0;
    for (int i = 0; i < n; i++)
    {
        int hh, mm, ss;
        pii t;
        scanf("%d:%d:%d", &hh, &mm, &ss);
        t2 = 3600 * hh + 60 * mm + ss;
        t = t2 <= t1 ? time.add() : time.get();
        if (!(t.first + t.second & 1))
            cnt++;
        t1 = t2;
    }
    cout << cnt << endl;
}
int main()
{
    solve();
    return 0;
}
