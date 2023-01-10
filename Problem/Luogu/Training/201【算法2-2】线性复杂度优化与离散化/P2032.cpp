// P2032 扫描
// https://www.luogu.com.cn/problem/P2032
#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    vi a(n + 1);
    deque<int> qmax;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        while (!qmax.empty() && i - qmax.front() >= k)
            qmax.pop_front();
        while (!qmax.empty() && a[qmax.back()] < a[i])
            qmax.pop_back();
        qmax.push_back(i);
        if (i >= k)
            cout << a[qmax.front()] << endl;
    }
    return 0;
}