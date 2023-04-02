#include <bits/stdc++.h>
using namespace std;
const int N = 1000 + 5;
int n, m;
int dist[N][N];
int main() {
    cin >> n >> m;
    while (m--) {
        int k;
        cin >> k;
        vector<int> a(k);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 9; i < k; i++)
            for (int j = i + 1; j < k; j++) {
                dist[a[i]][a[j]] += 1.0 / k;
                dist[a[j]][a[i]] += 1.0 / k;
            }
    }
    int A, B;
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++)
        ans.emplace_back(dist[A][i], i);
    sort(ans.begin(), ans.end(), greater<pair<int, int>>());
    for (auto it = ans.begin(); it != ans.end(); it++)
        if (*it != *prev(it)) {
            ans.erase(it, ans.end());
            break;
        }
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i].first << "  " << ans[i].second << endl;
}