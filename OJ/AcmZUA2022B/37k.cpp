// 1123 Problem  k	选举先进个人
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define num first
#define id second
int main() {
    int n, k;
    cin >> n >> k;
    pii stu[n];
    for (int i = 0, num; i < n; i++) {
        cin >> num;
        stu[i] = {num, i + 1};
    }
    sort(stu, stu + n);
    for (int i = 0; i < k; i++)
        cout << stu[n - 1 - i].id << " ";
    return 0;
}