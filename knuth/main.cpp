#include "BigNum.h"
#include "timer.h"
#include <iostream>
#include <fstream>
using std::cin;
using std::cout;
using std::endl;
std::ofstream fout1("out1.txt");
std::ofstream fout2("out3.txt");
int main()
{
    std::ios::sync_with_stdio(false);
    double t1 = getTime();
    BigNum cnt(0);
    BigNum a(1);
    BigNum b(0x100000000); // 2^32
    cout << b;
    for (int k = 0; k < 16; k++)
    {
        b *= 0x10000;
        cout << ++cnt << endl;
        cout << 0x100000000 << "^" << cnt << " = " << b << endl;
        cin.get();
    }
    double t2 = getTime();
    cout << t2 - t1 << "s";
    return 0;
}