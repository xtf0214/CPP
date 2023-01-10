// 7-14 集合相似度
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()

int n;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k, a, b;
    cin >> n;
    vector<set<int>> s(n);
    for (int i = 0, m; i < n; i++)
    {
        cin >> m;
        for (int j = 0, x; j < m; j++)
            cin >> x, s[i].insert(x);
    }
    cin >> k;
    while (k--)
    {
        cin >> a >> b;
        a--, b--;
        vector<int> cap, cup;
        set_intersection(all(s[a]), all(s[b]), back_insert_iterator(cap));
        set_union(all(s[a]), all(s[b]), back_insert_iterator(cup));
        printf("%.2lf%\n", 100.0 * int(cap.size()) / int(cup.size()));
    }
    return 0;
}