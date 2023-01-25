#include <iostream>
using namespace std;
int H, A[100];
void maxHeapity(int i, int H)
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
        maxHeapity(largest, H);
    }
}
int main()
{
    cin >> H;
    for (int i = 1; i <= H; i++)
        cin >> A[i];
    for (int i = H / 2; i >= 1; i--)
        maxHeapity(i, H);
    for (int h = H; h >= 1; h--)
    {
        maxHeapity(1, h);
        swap(A[h], A[1]);
    }
    for (int i = 1; i <= H; i++)
        cout << A[i] << " ";
    cout << endl;
    return 0;
}