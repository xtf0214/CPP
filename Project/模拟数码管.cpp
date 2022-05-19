#include <iostream>
#include <string>
#include<algorithm>
using namespace std;
int main()
{

    char A[10][3][3];
    string num;
    for (int z = 0; z < 10; z++)
        for (int y = 0; y < 3; y++)
            for (int x = 0; x < 3; x++)
                A[z][y][x] = ' ';
    cin >> num;
    for (int y = 0; y < 3; y++)
    {
        for (int z = 0; z < 10; z++)
            for (int x = 0; x < 3; x++)
                cout << A[z][y][x];
        cout << endl;
    }

    return 0;
}
