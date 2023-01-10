// 	1045 Problem  c	统计元音的次数（第六讲）
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        int na = 0, ne = 0, ni = 0, no = 0, nu = 0;
        string a;
        getline(cin, a);
        for (int j = 0; j < a.size(); j++) {
            if (a[j] == 'a')
                na++;
            if (a[j] == 'e')
                ne++;
            if (a[j] == 'i')
                ni++;
            if (a[j] == 'o')
                no++;
            if (a[j] == 'u')
                nu++;
        }

        cout << "a:" << na << endl;
        cout << "e:" << ne << endl;
        cout << "i:" << ni << endl;
        cout << "o:" << no << endl;
        cout << "u:" << nu << endl;
        if (i != n - 1)
            cout << endl;
    }

    return 0;
}