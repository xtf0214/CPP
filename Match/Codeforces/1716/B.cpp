/** 
 * @file    :   Educational Codeforces Round 133 (Rated for Div. 2) B
 * @author  :   Tanphoon 
 * @date    :   2022/08/04 22:35
 * @version :   2022/08/04 22:35
 * @link    :   https://codeforces.com/contest/1716/problem/B
*/
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10000 + 5;
int main()
{
    int T, n;
    cin >> T;
    while (T--)
    {
        cin >> n;
        vector<int> arr(n);
        iota(arr.begin(), arr.end(), 1);
        cout << n << endl;
        for (int i : arr)
            cout << i << " ";
        cout << endl;
        for (int i = arr.size() - 1; i >= 1; i--)
        {
            swap(arr[i], arr[i - 1]);
            for (int i : arr)
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}