#include <iostream>
#include <algorithm>
using namespace std;
const int INF = (1 << 30);
void MergeSort(int *A, int left, int right)
{
    if (right - left <= 1)
        return;
    int mid = (left + right) / 2;
    MergeSort(A, left, mid);
    MergeSort(A, mid, right);
    inplace_merge(A + left, A + mid, A + right);
    // int n1 = mid - left, n2 = right - mid;
    // int L[n1 + 1], R[n2 + 1];
    // for (int i = 0; i < n1; i++)
    //     L[i] = A[left + i];
    // for (int i = 0; i < n2; i++)
    //     R[i] = A[mid + i];
    // L[n1] = R[n2] = INF;
    // for (int k = left, i = 0, j = 0; k < right; k++)
    //     (L[i] <= R[j]) ? (A[k] = L[i++]) : (A[k] = R[j++]);
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