#include <iostream>
using namespace std;
int Judge(int a, int b)
{
    if (a == b)
        return 0;
    if ((a == 0 && b == 1) || (a == 0 && b == 4) || (a == 1 && b == 2) || (a == 1 && b == 4) || (a == 2 && b == 3) || (b == 0 && a == 1) || (b == 0 && a == 4) || (b == 1 && a == 2) || (b == 1 && a == 4) || (b == 2 && a == 3))
        return (a < b) ? -1 : 1;
    else
        return (a < b) ? 1 : -1;
}
int main()
{
    int N, Na, Nb, p = 0, q = 0, Sa = 0, Sb = 0;
    int NA[201] = {0}, NB[201] = {0};
    cin >> N >> Na >> Nb;
    for (int i = 0; i < Na; i++)
        cin >> NA[i];
    for (int i = 0; i < Nb; i++)
        cin >> NB[i];
    for (int i = 0; i < N; i++)
    {
        switch (Judge(NA[p++], NB[q++]))
        {
        case 1:
            Sa++;
            break;
        case 0:
            break;
        case -1:
            Sb++;
            break;
        }
        if (p >= Na)
            p -= Na;
        if (q >= Nb)
            q -= Nb;
    }
    cout << Sa << " " << Sb << endl;
    return 0;
}