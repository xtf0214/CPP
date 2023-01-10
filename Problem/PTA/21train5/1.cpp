#include <bits/stdc++.h>
using namespace std;
int mx = 1;
char s1[55], s2[55];
void pan(int root, int star, int end, int depth) {
    if (star > end)
        return;
    mx = max(mx, depth);
    int i = star;
    while (s1[root] != s2[i]) {
        i++;
    }
    pan(root + 1, star, i - 1, depth + 1);
    pan(root + 1 + i - star, i + 1, end, depth + 1);
}
int main() {
    int n;
    cin >> n;
    cin >> s1 >> s2;
    pan(0, 0, n - 1, 1);
    cout << mx;
    return 0;
}