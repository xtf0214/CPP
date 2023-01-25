#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;
void Rand(int *p, int *q)
{
    srand(time(0));
    int n = q - p;
    for (int i = n - 1; i >= 1; i--)
        swap(p[i], p[rand() % i]);
    /* for (int i = 0; i <= n - 1; i++)
        swap(p[i], p[rand() % (n - i) + i]); */
}
int main()
{

    int A[100], n;
    cin >> n;
    for (int i = 0; i < n; i++)
        A[i] = i;
    while (true)
    {
        Rand(A, A + n);
        for (int i = 0; i < n; i++)
            cout << A[i] << " ";
        getchar();
    }
    return 0;
}