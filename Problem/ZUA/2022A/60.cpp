#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<pair<int, string>> a;
    stack<string> s1, s0;
    int n, gender;
    string name;
    cin >> n;
    for (int i = 0; i < n / 2; i++)
    {
        cin >> gender >> name;
        a.push_back({gender, name});
    }
    for (int i = 0; i < n / 2; i++)
    {
        cin >> gender >> name;
        if (gender == 0)
            s0.push(name);
        else
            s1.push(name);
    }
    for (auto i : a)
    {
        if (i.first == 0)
        {
            cout << i.second << " " << s1.top();
            s1.pop();
        }
        else
        {
            cout << i.second << " " << s0.top();
            s0.pop();
        }
        cout << endl;
    }
    return 0;
}