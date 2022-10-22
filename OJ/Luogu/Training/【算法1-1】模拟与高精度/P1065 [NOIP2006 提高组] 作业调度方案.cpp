#include <iostream>
using namespace std;
int n, m, Queue[405], cnt[25], J[25][25], T[25][25], LastT[25], Ans;
bool f[25][10005];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m * n; i++)
        cin >> Queue[i];
    for (int i = 1; i <= m; i++)
        for (int k = 1; k <= n; k++)
            cin >> J[i][k];
    for (int i = 1; i <= m; i++)
        for (int k = 1; k <= n; k++)
            cin >> T[i][k];
    for (int i = 1; i <= n * m; i++)
    {
        int j = J[Queue[i]][++cnt[Queue[i]]], t = T[Queue[i]][cnt[Queue[i]]], tot = 0, l;
        //J是当前工件工序所需机器， T是当前工序所需时间， tot是当前找到的连续时间长度
        for (l = LastT[Queue[i]] + 1;; l++)
        { //枚举时间
            if (f[j][l] == false)
                tot++;
            else
                tot = 0; //由于当前连续时间少于所需，而中间有一个时间点已被用过，所以只能抛弃前段时间。
            if (tot == t)
            {
                for (int k = l - tot + 1; k <= l; k++)
                    f[j][k] = true;  //将要用的时间置为true
                LastT[Queue[i]] = l; //更新结束时间
                Ans = max(Ans, l);   //更新答案
                break;               //跳出循环
            }
        }
    }
    cout << Ans;
}
