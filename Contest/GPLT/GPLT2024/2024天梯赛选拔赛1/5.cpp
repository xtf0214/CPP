/** 
 * @file    :   情人节
 * @author  :   Tanphoon 
 * @date    :   2023/12/25 09:49
 * @version :   2023/12/25 09:49
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<string> v;
    string s;
    while (cin >> s, s != ".") {
        v.push_back(s);
    }
    if (v.size() >= 14) {
        cout << v[1] << " and " << v[13] << " are inviting you to dinner...\n";
    } else if (v.size() >= 2) {
        cout << v[1] << " is the only one for you...\n";
    } else {
        cout << "Momo... No one is for you ...\n";
    }
}