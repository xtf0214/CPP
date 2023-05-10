// P1168 中位数
// https://www.luogu.com.cn/problem/P1168
#include <bits/stdc++.h>
using namespace std;
#define move(src, dst) dst.push(src.top()), src.pop()

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int n, x;
    cin >> n;
    cin >> x;
    maxHeap.push(x);
    cout << x << endl;
    for (int i = 2; i <= n; i++) {
        cin >> x;
        if (x > maxHeap.top())
            minHeap.push(x);
        else
            maxHeap.push(x);
        while (abs(int(maxHeap.size() - minHeap.size())) > 1)
            if (maxHeap.size() > minHeap.size())
                move(maxHeap, minHeap);
            else
                move(minHeap, maxHeap);
        if (i % 2 == 1)
            cout << (maxHeap.size() > minHeap.size() ? maxHeap.top() : minHeap.top()) << endl;
    }
    return 0;
}