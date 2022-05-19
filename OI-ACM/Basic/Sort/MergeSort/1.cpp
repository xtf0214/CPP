#include <iostream>
using namespace std;
int t[1000]; //用于暂时存放合并的元素的空数组
void MergeSort(int *A, int left, int right)
{
    //分
    if (right - left <= 1)
        return; //递归出口
    int mid = (left + right) / 2;
    MergeSort(A, left, mid);
    MergeSort(A, mid, right);
    //治
    int i = left, j = mid;
    for (int k = left; k < right; k++)
    {
        if ((j > right - 1) || (i <= mid - 1 && A[i] <= A[j]))
            t[k] = A[i++];
        else
            t[k] = A[j++];
    } //合并
    for (int k = left; k < right; k++)
        A[k] = t[k]; //复制
}
int main()
{
    int A[1000], n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    MergeSort(A, 0, n);
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    return 0;
}