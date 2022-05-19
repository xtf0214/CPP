#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int age, hour, minute;
    string week;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> age >> week;
        scanf("%d:%d", &hour, &minute);
        if (age >= 18)
            cout << "Yes" << endl;
        else
        {
            if (week == "Fri" || week == "Sat" || week == "Sun")
            {
                if (hour == 20)
                    cout << "Yes" << endl;
                else
                    cout << "No" << endl;
            }
            else
                cout << "No" << endl;
        }
    }
    return 0;
}
