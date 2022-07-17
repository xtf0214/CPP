#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int c = 0;
    getline(cin, s);
    for (int i = s.find("HPU",0); i != -1;i=s.find("HPU",i+3))
        c++;
    cout << c << endl;
    return 0;
}