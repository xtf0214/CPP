#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 5;

int a[N];
int n, m, k, cnt;
map<int, int> mp;
void add(int i) {
    if (++mp[a[i]] == 1)
        cnt++;
}
void del(int i) {
    if (--mp[a[i]] == 0)
        cnt--;
}

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int ans = 0;
    while (m--) {
        int l, r;
        cin >> l >> r;
        l = min(l ^ ans, r ^ ans) + 1;
        r = max(l ^ ans, r ^ ans) + 1;
        
    }
}