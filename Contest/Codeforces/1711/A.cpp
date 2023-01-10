/** 
 * @file    :   Codeforces Round #810 (Div. 2) A
 * @author  :   Tanphoon 
 * @date    :   2022/07/24 22:35
 * @version :   2022/07/24 22:35
 * @link    :   https://codeforces.com/contest/1711/problem/A
*/
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10000 + 5;
int main()
{
    for (int i = 2; i <= 100; i++)
    {
        vector<int> a(i), b(i);
        int score = 1000000;
        for (int j = 1; j <= i; j++)
            a[j - 1] = j;
        do
        {
            int cnt = 0;
            for (int j = 1; j <= i; j++)
                cnt += a[j - 1] % j == 0 ? 1 : 0;
            if (cnt < score)
            {
                score = cnt;
                b = a;
            }
        } while (next_permutation(a.begin(), a.end()));
        for (int i : b)
            cout << i << " \n"[i == b[b.size() - 1]];
    }
    return 0;
}
/* 
1
2 1

1 3 2
1 3 4 2

1 3 2 5 4
1 3 2 5 6 4

1 3 2 5 4 7 6
1 3 2 5 4 7 8 6

1 3 2 5 4 7 6 9 8
1 3 2 5 4 7 6 9 10 8

1 3 2 5 4 7 6 9 8 11 10 */