/**
 * @file    :   Problem F. Art for Last    单调队列
 * @author  :   Tanphoon
 * @date    :   2023/05/14 16:44
 * @version :   2023/05/14 16:44
 * @link    :   https://codeforces.com/gym/104354/problem/F
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a.begin() + 1, a.end());
    for (int i = 1; i <= n; i++)
        b[i] = a[i] - a[i - 1]; // query(x,y) = max[x+1,y]

    long long ans = INT64_MAX;
    deque<int> q;
    for (int i = 2; i <= n; i++) {
        while (!q.empty() && i - q.front() >= k - 1) // 查询差分数组的区间长度为k-1
            q.pop_front();
        while (!q.empty() && b[q.back()] > b[i])
            q.pop_back();
        q.push_back(i);
        if (i >= k) {
            ans = min(ans, 1LL * (a[i] - a[i - k + 1]) * b[q.front()]);
        }
    }
    cout << ans << endl;
}