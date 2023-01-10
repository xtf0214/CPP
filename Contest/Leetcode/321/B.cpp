#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
template <typename T>
using vT = vector<T>;
template <typename T>
using vvT = vector<vector<T>>;
#define all(v) v.begin(), v.end()
#define print(v) for (int i = 0; i < v.size(); cout << v[i] << " \n"[++i == v.size()])
#define F first
#define S second
#define lowbit(x) x &(-x)
const int vec[4][2]{{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
const int N = 1e6 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;

class Solution
{
public:
    int appendCharacters(string s, string t)
    {
        int i = 0;
        for (int j = 0; j < s.size(); j++)
            while (i < t.size() && s[j] == t[i])
                i++;
        return t.size() - i;
    }
};
int main()
{
    Solution res;
    vector<int> nums{};
    return 0;
}