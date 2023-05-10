// P1801 黑匣子
// https://www.luogu.com.cn/problem/P1801
#include <bits/stdc++.h>
using namespace std;
#define move(src, dst) dst.push(src.top()), src.pop()
priority_queue<int, vector<int>, less<int>> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int l = 0;
    for (int k = 1; k <= m; k++) {
        int r;
        cin >> r;
        while (l < r) {
            maxHeap.push(a[l++]);
            if (maxHeap.size() >= k)
                move(maxHeap, minHeap);
        }
        cout << minHeap.top() << endl; // maxHeap里有k-1个元素，答案在minHeap头部
        move(minHeap, maxHeap); // maxHeap容量+1，把第i小放在maxHeap头部和待输入元素比较
    }
    return 0;
}