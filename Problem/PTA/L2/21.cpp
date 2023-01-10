// 7-21 点赞狂魔
#include <bits/stdc++.h>
using namespace std;

struct T
{
    int num;
    string id;
    int count;
};
bool cmp(const T &a, const T &b)
{
    return a.count != b.count ? a.count > b.count : a.num < b.num;
}
signed main()
{
    int n;
    set<int> s;
    cin >> n;
    T a[n];
    for (int i = 0; i < n; i++)
    {
        int num, x;
        string id;
        cin >> id >> num;
        a[i].id = id, a[i].num = num;
        while (num--)
            cin >> x, s.insert(x);
        a[i].count = s.size();
        s.clear();
    }
    sort(a, a + n, cmp);
    vector<string> ans;
    for (int i = 0; i < min(n, 3); i++)
        ans.push_back(a[i].id);
    for (int i = ans.size(); i < 3; i++)
        ans.push_back("-");
    for (int i = 0; i < 3; i++)
        cout << ans[i] << " \n"[i == 2];
    return 0;
}