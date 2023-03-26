#include <iostream>
using namespace std;
int H, A[100];
int parent(int x) { return x >> 1; }
int left(int x) { return x << 1; }
int right(int x) { return x << 1 | 1; }

int main() {

    cin >> H;
    for (int i = 1; i <= H; i++)
        cin >> A[i];
    for (int i = 1; i <= H; i++) {
        cout << "node " << i << ": key = " << A[i] << ",";
        if (parent(i) >= 1)
            cout << "parent key = " << A[parent(i)] << ",";
        if (left(i) <= H)
            cout << "left key = " << A[left(i)] << ",";
        if (right(i) <= H)
            cout << "right key = " << A[right(i)] << ",";
        cout << endl;
    }
    return 0;
}