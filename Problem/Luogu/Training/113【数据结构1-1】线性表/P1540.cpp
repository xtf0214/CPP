/** 
 * @file    :   P1540 [NOIP2010 提高组] 机器翻译
 * @author  :   Tanphoon 
 * @date    :   2023/03/16 19:26
 * @version :   2023/03/16 19:26
 * @link    :   https://www.luogu.com.cn/problem/P1540
*/
#include <bits/stdc++.h>
using namespace std;

int Hash[1005] = {0};
queue<int> ram;

int main()
{
    int m, n;
    cin >> m >> n;
    int count = 0;
    while (n--)
    {
        int en;
        cin >> en;
        if (!Hash[en])
        {
            if (ram.size() >= m) ////////
            {
                Hash[ram.front()] = 0;
                ram.pop();
            }
            count++;
            ram.push(en);
            Hash[en] = 1;
            // cout << ram.size() << endl;
        }
    }
    cout << count;

    return 0;
}
