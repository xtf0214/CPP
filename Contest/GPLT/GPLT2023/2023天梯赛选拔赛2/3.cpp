#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    while (s.back() == '0')
        s.pop_back();
    if (s[0] == '-') {
        reverse(s.begin() + 1, s.end());
    } else {
        reverse(s.begin(), s.end());
    }
    cout << s;
}