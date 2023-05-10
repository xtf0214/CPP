#include <bits/stdc++.h>
using namespace std;
int n, m, k;

int main() {
    cin >> n >> m >> k;
    long long ans;
    while(m--) {
        int l, r;
        cin >> l >> r;
        ans += r - l;
    }
    cout << ans;
}