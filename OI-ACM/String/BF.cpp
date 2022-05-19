#include <iostream>
#include <string>
using namespace std;
/*返回字符串s中含有字串ss的个数*/
int SearchSubstr(string s, string ss)
{
    int cnt = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == ss[0])
        {
            bool find = true;
            for (int j = 0; j < ss.size(); j++)
                if (i + j >= s.size() || s[i + j] != ss[j])
                {
                    find = false;
                    break;
                }
            if (find)
                cnt++;
        }
    return cnt;
}
int BF(string s, string ss, int pos)
{
    int j = 0;
    while (pos < s.size() && j < ss.size())
    {
        if (s[pos] == ss[j])
            pos++, j++;
        else
            pos = pos - j + 1, j = 0;
    }
    if (j >= ss.size())
        return pos - j;
    else
        return -1;
}
int main()
{
    string s = "1234123512", ss = "123";
    int pos = -3;
    while ((pos = BF(s, ss, pos + 3)) != -1)
    {
        cout << pos << endl;
    }
}