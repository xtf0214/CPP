/** 
 * @file    :   J
 * @author  :   Tanphoon 
 * @date    :   2023/08/01 11:26
 * @version :   2023/08/01 11:26
 * @link    :   https://ac.nowcoder.com/acm/contest/62332/J
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a;
    while (n--) {
        int x;
        cin >> x;
        if (x & 1) 
            a.push_back(x);
    }
    cout << *max_element(a.begin(), a.end());
    return 0;
}