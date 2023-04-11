#include <bits/stdc++.h>
using namespace std;

struct Tire {
    int nxt[100000][26], cnt;
    bool exist[100000]; // 该结点结尾的字符串是否存在

    void insert(string s) { // 插入字符串
        int p = 0;
        for (char c : s) {
            c -= 'a';
            if (!nxt[p][c])
                nxt[p][c] = ++cnt; // 如果没有，就添加结点
            p = nxt[p][c];
        }
        exist[p] = 1;
    }

    bool find(string s) { // 查找字符串
        int p = 0;
        for (char c : s) {
            c -= 'a';
            if (!nxt[p][c])
                return false;
            p = nxt[p][c];
        }
        return exist[p];
    }
} tire;
int main() {
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        tire.insert(s);
    }
    cout << tire.find("ans");
}
/* 
6
an
as
ans
at
bed
bet
 */