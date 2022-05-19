#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000000 + 10;
bool prime[MAX];
void ertoc()
{
    fill(prime, prime + MAX, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= MAX; i++)
        if (prime[i])
            for (int j = 2 * i; j <= MAX; j += i)
                prime[j] = false;
    // for (int i = 1; i <= 100; i++)
    //     if (prime[i])
    //         cout << i << " ";
}
int main()
{
    int cnt = 0;
    ertoc();
    int m, n;
    vector<int> a;
    cin >> m >> n;
    for (int i = m; i <= n; i++)
        if (prime[i])
            a.push_back(i);
    for (int i = 0; i < a.size() - 2; i++)
        for (int j = i + 1; j < a.size() - 1; j++)
            for (int k = j + 1; k < a.size(); k++)
            {
                if (prime[a[i] * a[j] + a[k]] && prime[a[i] * a[k] + a[j]] && prime[a[j] * a[k] + a[i]])
                    // printf("%d, %d, %d\n", a[i], a[j], a[k]);
                    cnt++;
            }
    cout << cnt;
    return 0;
}