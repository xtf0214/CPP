/* 
问题描述
　　小蓝有一个由大写字母 ABCDEF 组成的字符串 S ，长度为 n，字符串的下标依次为 0 到 n-1 。
　　小蓝按照如下方法生成一个无限长的字符串：
　　首先选定一个 0 到 n-1 之间的数，作为初始下标。
　　从初始下标开始，将下标对应的字符加入到字符串的结尾，将字符的序号（A到F依次对应 1 到 6 ）与下标相加作为新的下标值，如果下标大于等于 n，将其对 n 求余。重复此过程，即得到无限长的字符串。
　　例如，对于字符串 ACDF，当初始下标是 0 时，生成的字符串为：ACACACACAC...
　　再如，对于字符串 DCBA，当初始下标是 1 时，生成的字符串为：CDDDDDDDDD...
　　给定小蓝的字符串 S，请问当初始下标为多少时，生成的字符串最小。
输入格式
　　输入一行包含一个字符串。
输出格式
　　输出一行，包含一个整数，为所求的下标，如果有多个下标满足要求，输出最小的那个。
样例输入
DCBA
样例输出
3
样例输入
AAAA
样例输出
0
评测用例规模与约定
　　令 |S| 表示 S 的长度。
　　对于 30% 的评测用例，1 <= |S| <= 100。
　　对于 50% 的评测用例，1 <= |S| <= 1000。
　　对于 70% 的评测用例，1 <= |S| <= 10000。
　　对于 80% 的评测用例，1 <= |S| <= 100000。
　　对于所有评测用例，1 <= |S| <= 1000000。 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#define lowbit(x) x &(-x)
#define print(v) for (int i = 0; i < v.size(); cout << v[i] << " \n"[i++ == v.size() - 1])
const int N = 1e6 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;
const int vec[4][2]{{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s, res;
    int n;
    map<char, int> mp;
    cin >> s;
    n = s.size();
    for (int i = 0; i < s.size(); i++)
        mp[s[i]] = i;
    int id = 0;
    res.push_back(s[id]);
    for (int i = 0; i < 10; i++)
        res.push_back(s[(mp[res.back()] + res.back() - 'A' + 1) % n]);
    cout << res;
    // for (int i = 0; i < s.size();i++)

    return 0;
}