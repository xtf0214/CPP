#include <bits/stdc++.h>
using namespace std;
struct Person
{
    string name;
    double score;
};
int main()
{
    Person A[10];
    int n;
    cin >> n;
    for (int i = 0, a, b, c; i < n; i++)
    {
        cin >> A[i].name;
        cin >> a >> b >> c;
        A[i].score = a + b - c;
    }
    for (int i = 0, a, b, c; i < n; i++)
    {
        cout << A[i].name << " ";
        printf("%.2lf\n", A[i].score);
    }
    return 0;
}
