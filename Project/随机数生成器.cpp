#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void Rand(int *p, int *q)
{
    srand(time(0));
    int n = q - p;
    for (int i = n - 1; i >= 1; i--)
        swap(p[i], p[rand() % i]);
}
int main()
{
    system("chcp 65001");
    int a, b, n;
    int A[1000] = {0};
    cout << "分别输入三个数a，b，n以生成[a,b]的n个随机数" << endl;
    cin >> a >> b >> n;
    for (int i = 0, j = a; j <= b; i++, j++)
        A[i] = j;
    while (true)
    {
        Rand(A, A + b - a + 1);
        for (int i = 0; i < n; i++)
            cout << A[i] << " ";
        cout << endl;
        system("pause");
    }
    return 0;
}
