#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, k;
    string s, s1 = "qiandao", s2 = "easy";
    vector<string> a;
    scanf("%d %d\n", &n, &m);
    for (int i = 0; i < n; i++)
    {
        getline(cin, s);
        if (s.find("qiandao") == -1 && s.find("easy") == -1)
            a.push_back(s);
    }
    if (m >= a.size())
        cout << "Wo AK le";
    else
        cout << a[m];
    return 0;
}