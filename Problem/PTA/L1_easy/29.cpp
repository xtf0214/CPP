// 7-29 统计字符出现的次数
#include <algorithm>
#include <iostream>
using namespace std;
struct Str
{
    int cnt, id;
    char c;
} a[60];
bool cmp(const Str &a, const Str &b) { return a.id < b.id; }
int main()
{
    string str;
    getline(cin, str);
    int n = 0;
    for (int i = 0; i < 52; i++)
        i < 26 ? a[i].c = i + 'a' : a[i].c = i - 26 + 'A';
    for (int i = 0; i < str.size(); i++)
    {
        if ('A' <= str[i] && str[i] <= 'Z')
        {
            int j = str[i] - 'A' + 26;
            a[j].cnt++;
            if (a[j].id == 0)
                a[j].id = i;
        }
        else if ('a' <= str[i] && str[i] <= 'z')
        {
            int j = str[i] - 'a';
            a[j].cnt++;
            if (a[j].id == 0)
                a[j].id = i;
        }
        else
            n++;
    }
    sort(a, a + 52, cmp);

    for (int i = 0, k = 0; i < 52; i++)
    {
        if (a[i].cnt != 0)
        {
            k % 10 == 0 ? printf("%c--%d", a[i].c, a[i].cnt) : printf(" %c--%d", a[i].c, a[i].cnt);
            k++;
            if (k % 10 == 0)
                printf("\n");
        }
    }
    return 0;
}
// a bb ccc dddd ee ff gg hh ii jj kk ll mm nn oo pp qq rr ss tt uu vv