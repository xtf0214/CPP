/** 
 * @file    :   L
 * @author  :   Tanphoon 
 * @date    :   2023/08/01 17:58
 * @version :   2023/08/01 17:58
 * @link    :   https://ac.nowcoder.com/acm/contest/62332/L
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, h;
    cin >> n >> h;
    vector<pair<int, int>> v(n);
    for (auto &[a, b] : v)
        cin >> a >> b;
    sort(v.begin(), v.end());
    auto lst = v.back();
    sort(v.begin(), v.end() - 1, [](const auto &x, const auto &y){
        return x.second != y.second ? x.second > y.second : x.first < y.first;
    }); 
    ll cnt = 0;
    for (int i = 0; i < n - 1; i++) {
        if (v[i].second >= lst.first) {
            h -= v[i].second;
            cnt++;
            if (h < 0) {
                cout << cnt << '\n';
                return 0;
            }
        }
    }
    if (lst.first > lst.second) {
        cnt += (h - 1) / lst.first + 1;
    } else {
        cnt += 1 + (h - lst.second - 1) / lst.first + 1;
    }
    cout << cnt << '\n';
}