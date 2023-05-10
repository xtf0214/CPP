// P3378 堆
// https://www.luogu.com.cn/problem/P3378
#include <bits/stdc++.h>
using namespace std;

template <typename T, typename Cmp = less<T>> struct Heap {
    vector<T> dat;
    Heap(const vector<T> &v = vector<T>()) : dat(v) { make_heap(dat.begin(), dat.end(), Cmp()); }
    void push(T x) { dat.push_back(x), push_heap(dat.begin(), dat.end(), Cmp()); }
    void pop() { pop_heap(dat.begin(), dat.end(), Cmp()), dat.pop_back(); }
    T top() { return dat[0]; }
};

signed main() {
    Heap<int, greater<int>> a;
    int n;
    cin >> n;
    while (n--) {
        int op, x;
        cin >> op;
        if (op == 1) {
            cin >> x, a.push(x);
        } else if (op == 2) {
            cout << a.top() << endl;
        } else {
            a.pop();
        }
    }
    return 0;
}