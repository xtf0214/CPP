/**
 * @file    :   7-10 老板的作息表
 * @author  :   Tanphoon
 * @date    :   2023/04/20 02:21
 * @version :   2023/04/20 02:21
 * @link    :
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<string, string>> time;
    for (int i = 0; i < n; i++) {
        string a, b;
        char c;
        cin >> a >> c >> b;
        time.push_back({a, b});
    }
    sort(time.begin(), time.end());
    if (time.front().first != "00:00:00")
        cout << "00:00:00"
             << " - " << time.front().first << endl;
    for (int i = 1; i < time.size(); i++)
        if (time[i - 1].second != time[i].first)
            cout << time[i - 1].second << " - " << time[i].first << endl;
    if (time.back().second != "23:59:59")
        cout << time.back().second << " - "
             << "23:59:59" << endl;
    return 0;
}