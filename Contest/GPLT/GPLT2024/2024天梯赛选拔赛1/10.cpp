/**
 * @file    :   列车调度
 * @author  :   Tanphoon
 * @date    :   2023/12/24 22:34
 * @version :   2023/12/24 22:34
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    vector<int> t{a[0]};
    for (int i = 1; i < n; i++) {
        auto pos = lower_bound(t.begin(), t.end(), a[i]);
        if (pos == t.end()) {
            t.push_back(a[i]);
        } else {
            *pos = a[i];
        }
    }
    cout << t.size();
}