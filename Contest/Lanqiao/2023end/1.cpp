#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
#define db(x) cout << #x << " = " << x << endl
int a[]{5, 6, 8, 6, 9, 1, 6, 1, 2, 4, 9, 1, 9, 8, 2, 3, 6, 4, 7, 7, 5, 9, 5, 0, 3, 8, 7, 5, 8, 1, 5, 8, 6, 1,
        8, 3, 0, 3, 7, 9, 2, 7, 0, 5, 8, 8, 5, 7, 0, 9, 9, 1, 9, 4, 4, 6, 8, 6, 3, 3, 8, 5, 1, 6, 3, 4, 6, 7,
        0, 7, 8, 2, 7, 6, 8, 9, 5, 6, 5, 6, 1, 4, 0, 1, 0, 0, 9, 4, 8, 0, 9, 1, 2, 8, 5, 0, 2, 5, 3, 3};
int main() {
    int n = 100;
    set<string> st;
    int month[13]{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    for (int y1 = 0; y1 < n; y1++)
        if (a[y1] == 2)
            for (int y2 = y1 + 1; y2 < n; y2++)
                if (a[y2] == 0)
                    for (int y3 = y2 + 1; y3 < n; y3++)
                        if (a[y3] == 2)
                            for (int y4 = y3 + 1; y4 < n; y4++)
                                if (a[y4] == 3)
                                    for (int m1 = y4 + 1; m1 < n; m1++)
                                        for (int m2 = m1 + 1; m2 < n; m2++)
                                            for (int d1 = m2 + 1; d1 < n; d1++)
                                                for (int d2 = d1 + 1; d2 < n; d2++) {
                                                    int m = a[m1] * 10 + a[m2];
                                                    int d = a[d1] * 10 + a[d2];
                                                    if (1 <= m && m <= 12)
                                                        if (1 <= d && d <= month[m]) {
                                                            string ans = to_string(m * 100 + d);
                                                            st.insert(ans);
                                                        }
                                                }
    for (auto &x : st)
        cout << x << endl;
    db(st.size());
    return 0;
}
