// 1046 Problem  d	Ignatius and the Princess IV（第六讲）
#include <bits/stdc++.h>
using namespace std;
int arr[99999];
int main() {
    int n, num, answer;
    while (cin >> n) {
        int flag = (n + 1) / 2;
        memset(arr, 0, sizeof(arr));
        while (n--) {
            cin >> num;
            arr[num]++;
            if (arr[num] >= flag) {
                answer = num;
            }
        }
        cout << answer << endl;
    }
    return 0;
}