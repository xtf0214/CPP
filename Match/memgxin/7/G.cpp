#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvll = vector<vll>;
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#define print(v) for (int i = 0; i < v.size(); cout << v[i] << " \n"[i == v.size() - 1], ++i)
const int N = 1e6 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s;
    map<char, int> mp;
    vector<char> que;
    int ch[128]{0};
    cin >> s;
    for (auto &i : s)
        ch[i]++;
    for (int i = 'a'; i <= 'z'; i++)
        if (ch[i])
            mp[i] = ch[i];
    while (!mp.empty())
    {
        for (auto &[ch, i] : mp)
        {
            cout << ch;
            i--;
            if (i == 0)
                que.push_back(ch);
        }
        for (char ch : que)
            mp.erase(ch);
        que.clear();
    }

    return 0;
}