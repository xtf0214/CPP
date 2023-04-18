/**
 * @file    :   7-93 秀恩爱分得快
 * @author  :   Tanphoon
 * @date    :   2023/04/18 00:35
 * @version :   2023/04/18 00:35
 * @link    :
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;

vector<string> photo[N];
unordered_map<string, vector<int>> peo;
int n, m;
bool difsex(string &a, string &b) { return (a[0] == '-' && isdigit(b[0])) || (isdigit(a[0]) && b[0] == '-'); }
int main() {
    cin >> n >> m;
    for (int i = 1, k; i <= m; i++) {
        cin >> k;
        while (k--) {
            string x;
            cin >> x;
            photo[i].push_back(x);
            peo[x].push_back(i);
        }
    }
    string A, B;
    cin >> A >> B;
    unordered_map<string, unordered_map<string, double>> G;
    double mxa = 0, mxb = 0;
    for (auto u : {A, B})
        for (int i : peo[u])
            for (auto &v : photo[i])
                if (difsex(u, v))
                    G[u][v] += 1.0 / photo[i].size();
    for (auto &[k, v] : G[A])
        mxa = max(mxa, v);
    for (auto &[k, v] : G[B])
        mxb = max(mxb, v);
    if (mxa == mxb && G[A][B] == mxa) {
        cout << A << " " << B << endl;
        return 0;
    }

    auto cmp = [](const auto &a, const auto &b) -> bool {
        return a.second != b.second ? a.second > b.second : abs(stoi(a.first)) < abs(stoi(b.first));
    };
}