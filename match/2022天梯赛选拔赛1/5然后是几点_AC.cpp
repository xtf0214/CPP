#include <iostream>
using namespace std;
int main()
{
    int t1, tp;
    int hour, minute;
    cin >> t1 >> tp;
    minute = t1 % 100;
    hour = t1 / 100;
    if (tp > 0)
    {
        minute += tp;
        hour += minute / 60;
        minute %= 60;
        hour %= 24;
    }
    else
    {
        minute += tp;
        hour += minute / 60;
        minute %= 60;
        if (minute < 0)
        {
            minute = (minute + 60) % 60;
            hour -= 1;
        }
        if (hour < 0)
            hour = hour % 24 + 24;
    }
    printf("%d%02d", hour, minute);
    return 0;
}