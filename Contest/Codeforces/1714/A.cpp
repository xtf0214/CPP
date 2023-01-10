#include <bits/stdc++.h>
#define fr first
#define sc second
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int N = 1e6 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;
void print(int it) { cout << it << " "; }
void solve()
{
    int n, H, M, t1, t2;
    cin >> n >> H >> M;
    t1 = H * 60 + M;
    t2 = 0x3f3f3f3f;
    for (int i = 0; i < n; i++)
    {
        cin >> H >> M;
        t2 = min(t2, H * 60 + M);
    }
}
int main()
{
    int T;
    vector<int> a{1, 2, 3};
    cout << __gcd(961, 432);
    // cin >> T;
    // while (T--)
    //     solve();
    return 0;
}