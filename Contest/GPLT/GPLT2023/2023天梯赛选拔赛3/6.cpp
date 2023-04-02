#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, a, b;
    cin >> s;
    stringstream strin(s);
    vector<string> res;
    while (getline(strin, s, ','))
        res.push_back(s);
    s = res[0], a = res[1], b = res[2];
    int p1 = s.find(a), p2 = s.rfind(b);
    if (p1 != -1 && p2 != -1)
        cout << p2 - (p1 + a.size());
    else
        cout << -1;
    return 0;
}