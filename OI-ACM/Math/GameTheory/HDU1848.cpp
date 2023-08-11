/** 
 * @file    :   HDU1848
 * @author  :   Tanphoon 
 * @date    :   2023/08/11 21:28
 * @version :   2023/08/11 21:28
 * @link    :   http://acm.hdu.edu.cn/showproblem.php?pid=1848
 */
#include <bits/stdc++.h>
using namespace std;

int mex(const vector<int> &v) {
    set<int> s(v.begin(), v.end());
    for (int i = 0;; i++)
        if (s.find(i) == s.end())
            return i;
}
vector<int> getSG(int n, const vector<int> &f) {
    vector<int> SG(n + 1);
    for (int i = 1; i <= n; i++) {
        vector<int> S;
        for (int j = 0; f[j] <= i && j < f.size(); j++)
            S.push_back(SG[i - f[j]]);
        SG[i] = mex(S);
    }
    return SG;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int a, b, c;
    vector<int> f(20);
    f[0] = f[1] = 1;
    for (int i = 2; i < 20; i++)
        f[i] = f[i - 1] + f[i - 2];
    auto SG = getSG(1000, f);
    while (cin >> a >> b >> c) {
        if (a == 0 && b == 0 && c == 0)
            break;
        int s = SG[a] ^ SG[b] ^ SG[c];
        puts(s ? "Fibo" : "Nacci");
    }
    return 0;
}
/* 
1 1 1
1 4 1
0 0 0

Fibo
Nacci
 */