#include <cmath>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
int main() {
    int T;
    bool used[26];
    string s;
    cin >> T;
    while (T--) {
        cin >> s;
        int cnt = 0;
        memset(used, false, sizeof(used));
        for (char i : s)
            if (!used[i - 'a']) {
                cnt++;
                if (cnt % 3 == 1 && cnt != 1)
                    memset(used, false, sizeof(used));
                used[i - 'a'] = true;
            }
        cout << int(ceil(cnt / 3.0)) << endl;
    }
    return 0;
}
