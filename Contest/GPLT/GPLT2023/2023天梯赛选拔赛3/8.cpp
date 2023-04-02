#include <bits/stdc++.h>
using namespace std;
int main() {
    string a, b, ans;
    set<char> s;
    getline(cin, a);
    getline(cin, b);
    for (char c : b)
        s.insert(c);
    for (char c : a)
        if (!s.count(c))
            ans.push_back(c);
    cout << ans;
}