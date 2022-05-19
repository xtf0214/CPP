#include <iostream>
using namespace std;
struct
{
    int W[6000], L[6000];
    int p = 0, score = 0;
    void add(char c)
    {
        if (c == 'W')
            W[p]++;
        else if (c == 'L')
            L[p]++;
        if ((W[p] >= score || L[p] >= score) && (W[p] - L[p] >= 2 || L[p] - W[p] >= 2))
            p++;
    }
    void print()
    {
        for (int i = 0; i <= p; i++)
            cout << W[i] << ':' << L[i] << endl;
        /* {
            if (i == p && p >= 1 && L[i] == 0 && W[i] == 0)
                break;
            cout << W[i] << ':' << L[i] << endl;
        } */
    }
} score11, score21;

int main()
{
    char c;
    score11.score = 11;
    score21.score = 21;
    while (cin >> c && c != 'E')
    {
        score11.add(c);
        score21.add(c);
    }
    score11.print();
    cout << endl;
    score21.print();
    return 0;
}