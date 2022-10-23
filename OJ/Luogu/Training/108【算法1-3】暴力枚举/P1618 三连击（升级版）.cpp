#include <iostream>
using namespace std;
bool Book[10], flag;
int A[10], a, b, c;

void Dfs(int step)
{
    if (step == 10)
    {
        int x = A[1] * 100 + A[2] * 10 + A[3];
        int y = A[4] * 100 + A[5] * 10 + A[6];
        int z = A[7] * 100 + A[8] * 10 + A[9];
        if (x * b == y * a && x * c == z * a && y * c == z * b)
            cout << x << " " << y << " " << z << endl, flag = true;
        return;
    }
    for (int i = 1; i <= 9; i++)
        if (Book[i] == false)
        {
            A[step] = i;
            Book[i] = true;
            Dfs(step + 1);
            Book[i] = false;
        }
}//对1~9全排列共9!次，其中每个数字在每次排列中都在不同的位置，于是可以设置1~9每个数字的位置表示抽到的数字进行检验是否符合条件
int main()
{
    cin >> a >> b >> c;
    Dfs(1);
    if (flag == false)
        cout << "No!!!";
    return 0;
}