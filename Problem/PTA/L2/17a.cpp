#include <iostream>
using namespace std;
int main() {
    string s;
    getline(cin, s);
    int dp[1001][1001] = {0}, cnt = 1;
    for (int i = 0; i < s.size(); i++) {
        dp[i][i] = 1;
        if (i < s.size() - 1) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = 1;
                cnt = 2;
            }
        }
    }
    for (int l = 3; l <= s.size(); l++) {
        for (int i = 0, j = i + l - 1; j < s.size(); i++, j++) {
            if (s[i] == s[j] && dp[i + 1][j - 1] == 1) {
                dp[i][j] = 1;
                cnt = j - i + 1;
            }
        }
    }
    printf("%d", cnt);
    return 0;
}
