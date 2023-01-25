#include <iostream>
using namespace std;
int H = 0, A[100];
const int INF = 100000000;
void MaxHeapity(int i)
{
    int l, r, largest;
    l = i * 2;
    r = i * 2 + 1;

    if (l <= H && A[l] > A[i])
        largest = l;
    else
        largest = i;
    if (r <= H && A[r] > A[largest])
        largest = r;

    if (largest != i)
    {
        swap(A[largest], A[i]);
        MaxHeapity(largest);
    }
}
void insert(int x)
{
    A[++H] = x;
    int i = H;
    while (i > 1 && A[i / 2] < A[i])
    {
        swap(A[i], A[i / 2]);
        i = i / 2;
    }
}
int extract()
{
    if (H < 1)
        return -10000000;
    int max = A[1];
    A[1] = A[H--];
    MaxHeapity(1);
    return max;
}
int main()
{
    insert(8);
    insert(2);
    cout << extract() << endl;
    cout << extract();
    return 0;
}