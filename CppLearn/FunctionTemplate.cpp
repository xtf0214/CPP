#include <bits/stdc++.h>
using namespace std;
template <typename T> void Swap(T &a, T &b) {
    T t = a;
    a = b;
    b = t;
}
template <typename T> void Sort(T *a, int n) {
    for (int i = 1; i < n; i++)
        for (int j = n - 1; j >= i; j--)
            if (a[j] < a[j - 1])
                swap(a[j], a[j - 1]);
}
int main() {
    int n = 5;
    int a1[n] = {1, 4, 2, 3, 5};
    double a2[n] = {0.8, 0.9, 1.4, 0.4, 2};
    char a3[n] = {'b', 'd', 'a', 'e', 'f'};

    Sort(a1, n);
    Sort(a2, n);
    Sort(a3, n);
    for (int i = 0; i < n; i++)
        cout << a1[i] << " ";
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << a2[i] << " ";
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << a3[i] << " ";
}