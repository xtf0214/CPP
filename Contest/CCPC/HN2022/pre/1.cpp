#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 10;
bool isPrime[N];
bool vis[N];
vector<int> Prime;
vector<int> a;
int cnt = 0;
void comb(int n, int m, int k, int st)
{
    if (k == m)
    {
        cnt++;
        for (int i = 0; i < m; i++)
            cout << a[i] << " \n"[i == m - 1];
        for (int i = 0; i < m; i++)
            for (int j = i + 1; j < m; j++)
            {
                // cout<<Prime[a[i]] + Prime[a[j]]<<endl;
                if (!isPrime[a[i] + a[j]])
                    return;
            }
        for (int i = 0; i < m; i++)
            cout << a[i] << " \n"[i == m - 1];
    }
    for (int i = st; i < n; i++)
        if (!vis[i])
        {
            vis[i] = true;
            a[k] = i;
            comb(n, m, k + 1, i + 1);
            vis[i] = false;
        }
}
int main()
{
    memset(isPrime, 1, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= N; i++)
        if (isPrime[i])
        {
            Prime.push_back(i);
            for (int j = 2 * i; j <= N; j += i)
                isPrime[j] = false;
        }

    // int len = Prime.size();
    // cout << len << endl;
    a.resize(3);
    comb(10005, 3, 0, 1);
    // for (int i = 0; i < 100; i++)
    //     if (isPrime[i])
    //         cout << i << " ";
    cout << cnt << endl;
}