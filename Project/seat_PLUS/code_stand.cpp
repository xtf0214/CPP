#include <bits/stdc++.h>
using namespace std;
string student[60]; //最多容纳60人
string seat[7][10]; //6行9列
int main()
{
    system("chcp 65001");
    srand(time(0));
    ifstream fin("name.txt");
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        fin >> student[i];
    while (true)
    {
        int s = 0;
        for (int i = n - 1; i >= 1; i--)
            swap(student[i], student[rand() % i]); //对n个学生进行洗牌算法乱序
        for (int y = 1; y <= 6; y++)
            for (int x = 1; x <= 9; x++)
            {
                if (s == n)
                    break;                 //人满即停
                seat[y][x] = student[s++]; //诸神归位
            }
        for (int y = 1; y <= 6; y++)
        {
            for (int x = 1; x <= 9; x++)
                cout << seat[y][x] << "    ";
            cout << endl;
        }
        system("pause");
    }
    return 0;
}
