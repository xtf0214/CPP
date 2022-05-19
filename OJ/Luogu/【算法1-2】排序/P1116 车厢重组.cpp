#include <iostream>
using namespace std;
const int INF = 100000000;
int cnt = 0;
void MergeSort(int *A, int left, int right)
{
    if (right - left <= 1)
        return;
    int mid = (left + right) / 2;
    MergeSort(A, left, mid);
    MergeSort(A, mid, right);
    int n1 = mid - left, n2 = right - mid;
    int *L = new int[n1 + 1];
    int *R = new int[n2 + 1];
    for (int i = 0; i < n1; i++)
        L[i] = A[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = A[mid + i];
    L[n1] = R[n2] = INF;
    for (int k = left, i = 0, j = 0; k < right; k++)
    {
        if (L[i] <= R[j])
            A[k] = L[i++];
        else
            A[k] = R[j++], cnt += n1 - i; //每放入一个R[j],L[]中剩余的元素(n1-i)个都比R[j]大,即为逆序数
    }
    delete[] L;
    delete[] R;
}
int main()
{
    int A[10005], n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    MergeSort(A, 0, n);
    cout << cnt;
    return 0;
}
