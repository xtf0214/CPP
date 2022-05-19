#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
bool cmp(const string &a, const string &b)
{
    return a + b > b + a; //使排序为字典序大的排列
}
int main()
{
    string A[25];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    sort(A, A + n, cmp);
    for (int i = 0; i < n; i++)
        cout << A[i];
    return 0;
}