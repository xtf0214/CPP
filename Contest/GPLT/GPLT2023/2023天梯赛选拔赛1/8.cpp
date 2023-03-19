#include <iostream>
using namespace std;

int main() {
    int n, m, s, ans = 0;
    int num[300] = {0};
    cin >> n >> m >> s;
    while (n--) {
        int a, b;
        cin >> a >> b;
        if (a >= 175) {
            if (b >= s) // 特殊批次的考试
                ans++;
            else if (++num[a] <= m) // 同一分数的人，最多选择m个
                ans++;
        }
    }
    cout << ans;
    return 0;
}
