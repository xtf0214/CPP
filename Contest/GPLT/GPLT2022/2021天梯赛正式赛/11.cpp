#include <bits/stdc++.h>
using namespace std;
typedef pair<vector<int>, int> pii_i;
map<vector<int>, int> m;
bool cmp(const pii_i &a, const pii_i &b)
{
    if (a.second == b.second)
        return a.first < b.first; //表示当数对的二号位置的数字相同时，比较一号位置，从小到大排序
    else
        return a.second > b.second; //表示数对的二号位不同时，从大到小排序
}
vector<int> vv;
int main()
{
    int N, M;
    cin >> N >> M;
    for (int i = 0, a; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> a;
            vv.push_back(a);
        }
        m[vv]++;
        vv.clear();
    }
    vector<pii_i> vt(m.begin(), m.end());
    sort(vt.begin(), vt.end(), cmp);
    cout << vt.size() << endl;
    for (auto i : vt)
    {
        cout << i.second;
        for (int j : i.first)
            cout << " " << j;
        cout << endl;
    }
    return 0;
}
