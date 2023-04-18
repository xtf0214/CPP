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
bool sex[N];
string id[N];

int main() {
    cin >> n >> m;
    for (int i = 1, k; i <= m; i++) {
        cin >> k;
        vector<int> a;
        while (k--) {
            string num;
            cin >> num;
            int x = abs(stoi(num));
            a.push_back(x);
            sex[x] = (num[0] == '-');
            id[x] = num;
        }
        for (int i = 0; i < k; i++)
            for (int j = i + 1; j < k; j++)
                if (int u = a[i], v = a[j]; sex[u] != sex[v])
                    G[v][u] = G[u][v] += 1.0 / k;
    }
    string A, B;
    cin >> A >> B;
    int a = abs(stoi(A)), b = abs(stoi(B));
    id[a] = A, id[b] = B;
    double mxa = 0, mxb = 0;
    for (int i = 0; i < n; i++)
}