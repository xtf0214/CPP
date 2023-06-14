/**
 * @file    :   4440. 照相
 * @author  :   Tanphoon
 * @date    :   2023/06/15 01:44
 * @version :   2023/06/15 01:44
 * @link    :   https://www.acwing.com/problem/content/4443/
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n / 2; i++) {
        char c1, c2;
        cin >> c1 >> c2;
        if (c1 == 'H' && c2 == 'G')
            a.push_back(0);
        else if (c1 == 'G' && c2 == 'H')
            a.push_back(1);
    }
    int ans = 0;
    for (int i = 0, j = 0; i < a.size();) {
        while (j < a.size() && a[j] == a[i])
            j++;
        ans++;
        if (j == a.size() && a[i] == 0)
            ans--;
        i = j;
    }
    cout << ans;
}