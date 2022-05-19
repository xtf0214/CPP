#include <bits/stdc++.h>
using namespace std;
struct Person
{
    string name;
    int y, m, d;
    char gender;
    string phone1, phone2;
};
int main()
{
    Person person[10];
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        Person &t = person[i];
        cin >> t.name;
        scanf("%d/%d/%d", &t.y, &t.m, &t.d);
        cin >> t.gender >> t.phone1 >> t.phone2;
    }
    cin >> m;
    for (int i = 0, x; i < m; i++)
    {
        cin >> x;
        if (x < n)
        {
            cout << person[x].name << " " << person[x].phone1 << " " << person[x].phone2 << " ";
            printf("%c %d/%02d/%02d\n", person[x].gender, person[x].y, person[x].m, person[x].d);
        }
        else
            cout << "Not Found" << endl;
    }
    return 0;
}
