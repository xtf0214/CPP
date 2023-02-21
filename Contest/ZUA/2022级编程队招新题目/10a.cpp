#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int main() {
    int arr[N];
    int n, m, i;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        arr[i] = i;
    list<int> a(arr + 1, arr + n + 1);
    while (m--) {
        cin >> i;
        a.remove(i);
        a.push_back(i);
    }
    i = 0;
    vector<int> ans;
    for (auto it = a.begin(); i < 5; i++, it++)
        ans.push_back(*it);
    sort(ans.begin(), ans.end());
    for (int i = 0; i < 5; i++)
        cout << ans[i] << " \n"[i == 4];
    return 0;
}