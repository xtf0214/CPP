#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

struct T {
    int num;
    string id;
    int cnt;
};
bool cmp(const T &a, const T &b) { return a.cnt != b.cnt ? a.cnt > b.cnt : a.num < b.num; }
T a[105];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        set<int> s;
        int x;
        cin >> a[i].id >> a[i].num;
        for (int j = 0; j < a[i].num; j++)
            cin >> x, s.insert(x);
        a[i].cnt = s.size();
    }
    sort(a, a + n, cmp);
    vector<string> ans(3, "-");
    for (int i = 0; i < min(n, 3); i++)
        ans[i] = a[i].id;
    for (int i = 0; i < 3; i++)
        cout << ans[i] << " \n"[i == 2];
    return 0;
}