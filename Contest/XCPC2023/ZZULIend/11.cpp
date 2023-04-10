#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool check(string sx, string sy, ll &dist) {
    if (sx.size() > 6 || sy.size() > 6)
        return false;
    ll x = stoi(sx), y = stoi(sy);
    dist = x * x + y * y;
    return dist <= 1000000;
}
int main() {
    string x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ll d1 = 0, d2 = 0;
    bool ok1 = check(x1, y1, d1);
    bool ok2 = check(x2, y2, d2);
    if (!ok1 && !ok2)
        cout << "Draw";
    else if (!ok1)
        cout << "Bob";
    else if (!ok2)
        cout << "Alice";
    else {
        if (d1 == d2)
            cout << "Draw";
        else if (d1 < d2)
            cout << "Alice";
        else
            cout << "Bob";
    }
    return 0;
}