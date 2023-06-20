#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string s;
    int n = 2023;
    for (int i = 1; i <= n; i++) {
        for (char c : to_string(i))
            if (c == '2' || c == '3' || c == '0')
                s += c;
    }
    ll ans = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '2')
            for (int j = i + 1; j < s.size(); j++)
                if (s[j] == '0')
                    for (int k = j + 1; k < s.size(); k++)
                        if (s[k] == '2')
                            for (int l = k + 1; l < s.size(); l++)
                                if (s[l] == '3') {
                                    ans++;
                                }
    }
    cout << ans << endl;
}