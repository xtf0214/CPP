#include <iostream>
using namespace std;
int main()
{
    int L[6] = {3, 4, 5, 6, 7}, R[6] = {1, 2, 3, 4, 5};
    L[5] = R[5] = 1000000; //设置结束标记为Infinity
    int A[10] = {0};
    for (int k = 0, i = 0, j = 0; k < 10; k++)
    {
        /* A[k] = (L[i] <= R[j]) ? L[i] : R[j];
        ((L[i] <= R[j]) ? i : j)++; */
        if (L[i] <= R[j])
            A[k] = L[i++];
        else
            A[k] = R[j++];
    }
    for (int i = 0; i < 10; i++)
        cout << A[i] << " ";
}