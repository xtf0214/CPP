//模拟栈实现
#include <iostream>
using namespace std;
struct Stuck
{
    int left, right;
    Stuck(int _left, int _right) { left = _left, right = _right; }
    Stuck() {}
} r[1000];
void QuickSort(int *A, int left, int right)
{
    int p = 0;
    r[p++] = Stuck(left, right);
    while (p)
    {
        p--;
        int left = r[p].left, right = r[p].right;
        if (right - left <= 1)
            continue;
        swap(A[left], A[(left + right) / 2]);
        int i = left, j = right - 1, t = A[left];
        while (i < j)
        {
            while (A[j] >= t && i < j)
                j--;
            while (A[i] <= t && i < j)
                i++;
            if (i < j)
                swap(A[i], A[j]);
        }
        swap(A[i], A[left]);
        r[p++] = Stuck(i + 1, right);
        r[p++] = Stuck(left, i);
    }
}
int main()
{
    int n, A[1000];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    QuickSort(A, 0, n);
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    return 0;
}