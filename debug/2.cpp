#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int k;
    vector<int> num;
    vector<int> ans;
    cin >> k;
    string s;
    cin >> s;
    for (int i = s.size() - 1; i >= 0; i--)
        num.push_back(s[i] - '0');
    if (k == 2)
    {
        for (int i = 0; i < num.size() / 3; i++)
            ans.push_back(num[i * 3] + 2 * num[i * 3 + 1] + 4 * num[i * 3 + 2]);
        int t;
        for (int i = num.size() / 3 * 3; i < num.size(); i++)
            t += num[i] * (1 << (i % 3));
        if (t != 0)
            ans.push_back(t);
        for (auto it = ans.rbegin(); it != ans.rend(); it++)
            cout << *it;
    }
    else
    {
        for (int i = 0; i < num.size(); i++)
            cout << num[i] / 4 % 2 << num[i] / 2 % 2 << num[i] % 2;
    }
}