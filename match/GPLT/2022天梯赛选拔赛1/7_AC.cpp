#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    int a[4] = {0};
    char c[4] = {'G', 'P', 'L', 'T'};
    getline(cin, str);
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == 'G' || str[i] == 'g')
            a[0]++;
        else if (str[i] == 'P' || str[i] == 'p')
            a[1]++;
        else if (str[i] == 'L' || str[i] == 'l')
            a[2]++;
        else if (str[i] == 'T' || str[i] == 't')
            a[3]++;
    }
    for (int i = 0;; i++)
    {
        int end = 0;
        for (int j = 0; j < 4; j++)
            if (a[j] > 0)
            {
                cout << c[j];
                a[j]--;
            }
            else
                end++;
        if (end == 4)
            break;
    }
    return 0;
}