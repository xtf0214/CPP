#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s, s1;
    int cnt = 0, k;
    cin >> k;
    getchar();
    getline(cin, s1);
    getline(cin, s);
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == s1[0])
        {
            bool find = true;
            for (int j = 0; j < s1.size(); j++)
            {
                if (i + j >= s.size() || s[i + j] != s1[j])
                    find = false;
            }
            if (find)
                cnt++;
            if (find && cnt == k)
                for (int j = 0; j < s1.size(); j++)
                {
                    if (s[i + j] >= 'a' && s[i + j] <= 'z')
                        s[i + j] = (s[i + j] + 1 - 'a') % 26 + 'a';
                    else if (s[i + j] >= 'A' && s[i + j] <= 'Z')
                        s[i + j] = (s[i + j] + 1 - 'A') % 26 + 'A';
                }
        }
    }
    cout << s;
}