#include <bits/stdc++.h>
using namespace std;

int n, ok = 1;
set<int> q;

int main() {

    while (cin >> n) {
        ok = 1;
        q.clear();
        q.insert(1);
        q.insert(2);
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            if (q.count(x)) {
                set<int> q2;
                int y;
                for (y = 1; y <= 3; y++)
                    if (!q.count(y))
                        break;
                q2.insert(x), q2.insert(y);
                q.clear();
                q = q2;
                q2.clear();
            } else
                ok = 0;
        }
        if (ok)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}