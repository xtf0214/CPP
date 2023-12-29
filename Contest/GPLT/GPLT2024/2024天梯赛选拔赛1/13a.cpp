/** 
 * @file    :   特殊堆栈
 * @author  :   Tanphoon 
 * @date    :   2023/12/24 22:01
 * @version :   2023/12/24 22:01
 */
#include <bits/stdc++.h>
using namespace std;

struct BIT {
    int n;
    vector<int> tr;
    BIT(int n) : n(n), tr(n + 1, 0) {}
    void add(int i, int d) {
        for (; i <= n; i += (i & -i))
            tr[i] += d;
    }
    int get(int i) {
        int s = 0;
        for (; i; i -= (i & -i))
            s += tr[i];
        return s;
    }
    int kth(int k) {
        int l = 0, r = n, mid;
        while (r - l > 1)
            (get(mid = (l + r) >> 1) < k) ? l = mid : r = mid;
        return r;
    }
};

int main() {
    int n;
    cin >> n;
    BIT bit(1e5);
    stack<int> s;
    while (n--) {
        string op;
        cin >> op;
        if (op == "Pop") {
            if (s.empty()) {
                cout << "Invalid\n";
            } else {
                bit.add(s.top(), -1);
                cout << s.top() << '\n';
                s.pop();
            }
        } else if (op == "Push") {
            int x;
            cin >> x;
            bit.add(x, 1);
            s.push(x);
        } else {
            if (s.empty()) {
                cout << "Invalid\n";
            } else {
                int k = (s.size() + 1) / 2;
                int val = bit.kth(k);
                cout << val << '\n';
            }
        }
    }
}