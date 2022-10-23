#include <iostream>
using namespace std;
int A[5000005], flag = false, k, n;
void QuickSort(int left, int right)
{
    if (right - left <= 1 || flag)
    {
        if (k == left)
            cout << A[left], flag = true;
        return;
    }
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
    if (k < i)
        QuickSort(left, i);
    else
        QuickSort(i, right);
}
int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    QuickSort(0, n);
    cout << endl;
    return 0;
}
/* #include <bits/stdc++.h>
using namespace std;
long long n, k, a[5000010];
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    nth_element(a, a + k, a + n); //使第k小整数就位
    printf("%d", a[k]);           //调用第k小整数
} */