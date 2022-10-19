// 1049 Problem  g 今年暑假不AC（第七讲）
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using vi = vector<int>;
#define bg second
#define ed first
#define all(v) v.begin(), v.end()

int main()
{
    int n;
    while (cin >> n && n)
    {
        vector<pii> work(n);
        int res = 1, pre = 0;
        for (int i = 0; i < n; i++)
            cin >> work[i].bg >> work[i].ed;
        sort(all(work));
        for (int i = 1; i < n; i++)
            if (work[i].bg >= work[pre].ed)
            {
                res++;
                pre = i;
            }
        cout << res << endl;
    }
    return 0;
}