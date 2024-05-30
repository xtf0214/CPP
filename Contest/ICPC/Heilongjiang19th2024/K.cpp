/**
 * @file    :   K
 * @author  :   Tanphoon
 * @date    :   2024/05/29 00:52
 * @version :   2024/05/29 00:52
 * @link    :   https://codeforces.com/gym/105163/problem/K
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, d;
    set<int> s;
    vector<int> v(4);
    for (int i = 0; i < 4; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    do {
        int a = v[0], b = v[1], c = v[2], d = v[3];
        s.insert(a + b + c + d);
        s.insert(a + b + c - d);
        s.insert(a + b + c * d);
        s.insert(a + b - c + d);
        s.insert(a + b - c - d);
        s.insert(a + b - c * d);
        s.insert(a + b * c + d);
        s.insert(a + b * c - d);
        s.insert(a + b * c * d);

        s.insert(a - b + c + d);
        s.insert(a - b + c - d);
        s.insert(a - b + c * d);
        s.insert(a - b - c + d);
        s.insert(a - b - c - d);
        s.insert(a - b - c * d);
        s.insert(a - b * c + d);
        s.insert(a - b * c - d);
        s.insert(a - b * c * d);

        s.insert(a * b + c + d);
        s.insert(a * b + c - d);
        s.insert(a * b + c * d);
        s.insert(a * b - c + d);
        s.insert(a * b - c - d);
        s.insert(a * b - c * d);
        s.insert(a * b * c + d);
        s.insert(a * b * c - d);
        s.insert(a * b * c * d);
    } while (next_permutation(v.begin(), v.end()));
    cout << s.size() << '\n';
}