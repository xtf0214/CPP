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

int n, m;
double G[N][N];
vector<int> peo[N];
vector<int> photo[N];

bool sex[N];
string id[N];

int getId(string &s) {
    int x = abs(stoi(s));
    sex[x] = s[0] == '-';
    id[x] = s;
    return x;
}
int main() {
    cin >> n >> m;
    for (int i = 1, k; i <= m; i++) {
        cin >> k;
        for (int j = 0; j < k; j++) {
            string num;
            cin >> num;
            int x = getId(num);
            peo[x].push_back(i);
            photo[i].push_back(x);
        }
    }
    string A, B;
    cin >> A >> B;
    int a = getId(A), b = getId(B);

    for (int u : {a, b})
        for (int i : peo[u])
            for (int v : photo[i])
                if (sex[u] != sex[v])
                    G[u][v] += 1.0 / photo[i].size();

    double mxa = 0, mxb = 0;
    for (int i = 0; i < n; i++)
        if (sex[i] != sex[a])
            mxa = max(mxa, G[a][i]);
    for (int i = 0; i < n; i++)
        if (sex[i] != sex[b])
            mxb = max(mxb, G[b][i]);
    if (G[a][b] == mxa && G[b][a] == mxb) {
        cout << id[a] << " " << id[b] << endl;
        return 0;
    } else {
        for (int i = 0; i < n; ++i)
            if (G[a][i] == mxa && sex[a] != sex[i])
                cout << id[a] << " " << id[i] << endl;
        for (int i = 0; i < n; ++i)
            if (G[b][i] == mxb && sex[b] != sex[i])
                cout << id[b] << " " << id[i] << endl;
    }
    return 0;
}