// 7-94 出栈序列的合法性
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m, n, k;
    cin >> m >> n >> k;
    for (int i = 0; i < k; i++)
    {
        int a[n];
        stack<int> s;
        int x = 1;
        bool is_right = true;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int j = 0; j < n;)
        {
            while (x <= a[j])
            {
                s.push(x++);
                if (s.size() > m)
                    is_right = false;
            }
            if (s.top() != a[j])
            {
                is_right = false;
                break;
            }
            else
            {
                s.pop();
                j++;
            }
        }
        cout << (is_right ? "YES" : "NO") << endl;
    }
}