#include <bits/stdc++.h>
using namespace std;

template <typename T, int l, int r> struct NegaIdArray {
    vector<T> dat;
    NegaIdArray(T a = 0) : dat(vector<T>(r - l + 1, a)) {}
    T &operator[](int i) { return dat[i - l]; }
};

int main() {
    vector arr(2, NegaIdArray<int, -4, 4>());
    for (int i = -4; i <= 4; i++)
        arr[0][i] = arr[1][i] = i;
    for (int i = -4; i <= 4; i++)
        cout << arr[0][i] << ' ';
    cout << endl;
    for (int i = -4; i <= 4; i++)
        cout << arr[1][i] << ' ';
}