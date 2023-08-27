/** 
 * @file    :   k
 * @author  :   Tanphoon 
 * @date    :   2023/08/24 18:22
 * @version :   2023/08/24 18:22
 * @link    :   https://ac.nowcoder.com/acm/contest/63746/K
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    deque<int> q;
    for (int i = 1; i <= n; i++) {
        while (!q.empty() && i - q.front() >= m)
            q.pop_front();
        while (!q.empty() && a[q.back()] > a[i])
            q.pop_back();
        q.push_back(i);
        if (i >= m)
            cout << a[q.front()] << '\n';
    }
}