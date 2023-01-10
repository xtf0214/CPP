// 1043 Problem  a	困难的串问题（第五讲）
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int S[50], L, n, cnt;
// 判断是否存在重复串
bool isRight(int cur)
{
    for (int len = 1; len * 2 <= cur + 1; len++)
    {
        bool equal = true;
        for (int k = 0; k < len; k++)
            if (S[cur - k] != S[cur - k - len])
                equal = false;
        if (equal)
            return false;
    }
    return true;
}
int dfs(int cur)
{ /*返回0代表已经得到解，不需要在进行搜索*/
    if (cur == n)
    {
        for (int i = 0; i < cur; i++)
            printf("%c", 'A' + S[i]);
        cout << endl;
        return 0;
    }
    for (int i = 0; i < L; i++)
    {
        S[cur] = i;
        if (isRight(cur))
            if (!dfs(cur + 1))
                return 0;
    }
    return 1;
}

int main()
{
    while (~scanf("%d%d", &n, &L))
    {
        cnt = 0;
        memset(S, 0, sizeof(S));
        dfs(0);
    }
    return 0;
}