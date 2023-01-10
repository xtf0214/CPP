// 7-4 最后一个单词
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s, s1;
    getline(cin, s);
    for (int i = s.size() - 2; s[i] != ' ' && i >= 0; i--)
        s1 += s[i];
    bool isWord = true;
    if (s1.size() == 0 || ('A' <= s1[s1.size() - 1] && s1[s1.size() - 1] <= 'Z')) //最后一个单词不存在或者首字母为大写
        isWord = false;
    for (char ch : s1)
        if (!(('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z')))
            isWord = false;
    if (isWord)
        for (int i = s1.size() - 1; i >= 0; i--)
            cout << s1[i];
    else
        printf("Error");
}