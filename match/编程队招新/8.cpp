#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    string common;
    cin >> n;
    string str[n];
    for (int i = 0; i < n; i++)
        cin >> str[i];
    for (int i = 0;; i++)
    {
        char ch = str[0][i];
        bool flag = false;
        for (int j = 1; j < n; j++)
            if (str[j][i] != ch || i >= str[j].size())
            {
                flag = true;
                break;
            }
        if (!flag)
            common += ch;
        else
            break;
    }
    if (common.size() == 0)
        cout << "Error";
    else
        cout << common;
    return 0;
}