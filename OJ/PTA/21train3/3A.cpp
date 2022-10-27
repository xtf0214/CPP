#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#define print(v) for (int i = 0; i < v.size(); cout << v[i] << (char[2][2]){" ", "\n"}[i == v.size() - 1], ++i)
const int N = 1e6 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;
const int vec[4][2]{{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

int calc(int a, char op, int b)
{
    if (op == '+')
        return a + b;
    else if (op == '-')
        return a - b;
    else if (op == '*')
        return a * b;
    else
        return a / b;
}
bool isOP(char c) { return (c == '+' || c == '-' || c == '*' || c == '/'); }
bool isInt(char c) { return ('0' <= c && c <= '9'); }
// void solve()
// {
//     char c;
//     string s;
//     stack<char> op;

//     while (cin >> c)
//         s.push_back(c);
//     while (s.size() != 1)
//     {
//         stack<char> num;

//         for (int i = s.size() - 3; i >= 0; i--)
//             if (isOP(s[i]) && isInt(s[i + 1]) && isInt(s[i + 2]))
//             {
//                 int res = calc(s[i + 1]-'0', s[i], s[i + 2]-'0');
//                 for (int i = 0; i < 3; i++)
//                     s.pop_back();
//                 num.push(res + '0');
//             }
//         while(!num.empty())
//         {
//             s.push_back(num.top());
//             num.pop();
//         }
//     }
// }
void solve()
{
    list<char> l;
    char c;
    while (cin >> c)
        l.push_back(c);
    while (l.size()!=1)
    {
        for (auto it = l.rbegin(); it !=)
            l.insert()
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
// + + 2 * 3 - 7 4 / 8 4
// + + 2 * 3 3 2