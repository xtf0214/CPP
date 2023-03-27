#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, flag = 1;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        int m = stoi(s.substr(0, 2));
        if (m < 19 || m > 22) {
            flag = false;
            cout << s << endl;
        } else {
            if (find_if_not(s.begin(), s.end(), [&](char c) { return isdigit(int(c)); }) != s.end()) {
                flag = false;
                cout << s << endl;
            }
            // for (int i = 0; i < s.size(); i++)
            //     if (!isdigit(s[i])) {
            //         flag = false;
            //         cout << s << endl;
            //     }
        }
    }
    if (flag)
        puts("OK");
}