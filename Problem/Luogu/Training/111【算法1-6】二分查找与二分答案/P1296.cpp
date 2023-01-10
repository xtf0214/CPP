// P1296 奶牛的耳语
// https://www.luogu.com.cn/problem/P1296
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n, d, s = 0, A[100000];
    cin >> n >> d;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    sort(A, A + n);
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
        {
            if (A[i] + d >= A[j])
                s++;
            else
                break;
        }
    cout << s << endl;
}