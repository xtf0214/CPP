#include <cstring>
#include <iostream>
using namespace std;

int main()
{
    string str;
    while (getline(cin, str))
    {                                 //!!!!
        int A[26] = {0}, a[26] = {0}; //计数
                                      //--------------------------------------
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] >= 'A' && str[i] <= 'Z')
            {
                A[str[i] - 'A']++;
            }
            if (str[i] >= 'a' && str[i] <= 'z')
            {
                a[str[i] - 'a']++;
            }
        }
        //----------------------------------------
        int cnt = 0;
        for (int i = 0; i < 26; i++) //从0开始
        {
            if (A[i])
            {
                cnt++;
                if (cnt % 10 == 1)
                {
                    cout << (char)(i + 'A') << "--" << A[i];
                }
                else if (cnt % 10 == 0)
                {
                    cout << ' ' << (char)(i + 'A') << "--" << A[i] << endl;
                }
                else
                {
                    cout << ' ' << (char)(i + 'A') << "--" << A[i];
                }
            }
        }
        for (int i = 0; i < 26; i++) //从0开始
        {
            if (a[i])
            {
                cnt++;
                if (cnt % 10 == 1)
                {
                    cout << (char)(i + 'a') << "--" << a[i];
                }
                else if (cnt % 10 == 0)
                {
                    cout << ' ' << (char)(i + 'a') << "--" << a[i] << endl;
                }
                else
                {
                    cout << ' ' << (char)(i + 'a') << "--" << a[i];
                }
            }
        }
        if (cnt % 10 == 0)
        { //更改位置
            ;
        }
        else
        {
            cout << endl;
        }
    }
}
