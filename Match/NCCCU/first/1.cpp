#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char n1, c1, n2, c2, n3;
        int a1, a2, a3, ans;
        cin >> n1 >> c1 >> n2 >> c2 >> n3;
        getchar();
        a1 = n1 - '0';
        a2 = n2 - '0';
        a3 = n3 - '0';
        switch (c1)
        {
        case '&':
            switch (c2)
            {
            case '&':
                ans = a1 & a2 & a3;
                break;
            case '|':
                ans = a1 & a2 | a3;
                break;
            case '^':
                ans = a1 & a2 ^ a3;
                break;
            default:
                break;
            }
            break;

        case '|':
            switch (c2)
            {
            case '&':
                ans = a1 | a2 & a3;
                break;
            case '|':
                ans = a1 | a2 | a3;
                break;
            case '^':
                ans = a1 | a2 ^ a3;
                break;
            default:
                break;
            }
            break;
        case '^':
            switch (c2)
            {
            case '&':
                ans = a1 ^ a2 & a3;
                break;
            case '|':
                ans = a1 ^ a2 | a3;
                break;
            case '^':
                ans = a1 ^ a2 ^ a3;
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
        cout << ans << endl;
    }
    return 0;
}