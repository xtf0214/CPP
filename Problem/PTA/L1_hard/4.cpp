// 7-4 Have Fun with Numbers
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> a;
    reverse_copy(s.begin(), s.end(), back_insert_iterator(a));
    for (int &i : a)
        i -= '0';
    vector<int> b(a.size());
    b.push_back(0);
    for (int i = 0; i < b.size() - 1; i++) {
        b[i] += a[i] * 2 % 10;
        b[i + 1] += a[i] * 2 / 10;
    }
    if (b.back() == 0)
        b.pop_back();
    vector c(b);
    sort(a.begin(), a.end());
    sort(c.begin(), c.end());
    puts(a == c ? "Yes" : "No");
    for (auto it = b.rbegin(); it != b.rend(); it++)
        cout << *it;
    return 0;
}