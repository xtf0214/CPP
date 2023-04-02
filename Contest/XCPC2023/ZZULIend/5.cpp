#include <bits/stdc++.h>
using namespace std;

int n;
char s[200006];

inline void check() {
    for (int i = n; i >= 1; i--) {
        if (s[i] > 'z')
            s[i] = 'a', s[i - 1] += 1;
        else
            break;
    }
}

int main() {
    cin >> n;
    scanf("%s", s + 1);
    int ok = 0;
    for (int i = n; i >= 1; i--)
        if (s[i] != 'z')
            ok = 1;
    if (!ok)
        printf("No solution\n");
    else {
        s[n] += 1;
        check();
        printf("%s", s + 1);
    }
    return 0;
}