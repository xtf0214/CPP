// 7-54 整数分解为若干项之和
#include <iostream>
#include <vector>
using namespace std;
int k = 0, n;
void dfs(int x, vector<int> ans, int st)
{
    if (x == 0)
    {
        cout << n << "=";
        for (int i = 0, l = ans.size(); i < l; i++)
            cout << ans[i] << (string[2]){"+", ""}[i == l - 1];
        cout<<";\n"[++k % 4 == 0 || ans[0] == n];
        return;
    }
    for (int i = st; i <= x; i++)
    {
        ans.push_back(i);
        dfs(x - i, ans, i);
        ans.pop_back();
    }
}
int main()
{
    cin >> n;
    dfs(n, {}, 1); 
    return 0;
}