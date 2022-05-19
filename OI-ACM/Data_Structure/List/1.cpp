#include <iostream>
#include "List.h"
using namespace std;
int main()
{
    List A;
    A.push(1);
    A.push(2);
    A.push(3);
    A.push(4);
    A.push(5);
    A.print();
    cout << "\nthe length of A = " << A.size() << endl;
    A.pop(3);
    A.print();
    cout << "\nthe length of A = " << A.size() << endl;
    cout << "A[2]=" << A[2];
    return 0;
}