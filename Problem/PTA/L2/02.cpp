// 7-2 英文单词排序
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<string> a;
    string s;
    while (cin >> s && s != "#")
        a.push_back(s);
    stable_sort(a.begin(), a.end(), [](const string &a, const string &b)
                { return a.size() < b.size(); });
    for (string i : a)
        cout << i << " ";
    return 0;
}