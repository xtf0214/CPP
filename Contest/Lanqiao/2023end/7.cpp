#include <bits/stdc++.h>
using namespace std;

#ifdef _LQDEBUG
#define db(x) cout << #x << " = " << x << endl
#define cin fin
fstream fin("C:\\Users\\Administrator\\Desktop\\input\\7.txt");
#endif

int main() {
    int k;
    long long ans = 0;
    cin >> k;
    string s;
    char a, b;
    cin >> s >> a >> b;
    int n = s.size();
    for (int L = k - 1; L < n; L++)
        for (int i = 0, j = i + L; i < n && j < n; i++, j++) {
            if (s[i] == a && s[j] == b)
                ans++;
        }
    cout << ans;
    return 0;
}
