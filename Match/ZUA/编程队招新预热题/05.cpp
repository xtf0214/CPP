#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    string str, tmp;
    scanf("%d ", &n);
    for (int i = 0; i < n; i++)
    {
        getline(cin, tmp);
        if (tmp.size() >= str.size())
            str = tmp;
    }
    cout << str << endl;
    return 0;
}