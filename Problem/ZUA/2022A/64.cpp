#include <bits/stdc++.h>
using namespace std;
struct Person
{
    string num;
    string name;
    int score;
};
int main()
{
    Person A[10];
    int n;
    double sum = 0;
    cin >> n;
    for (int i = 0, a, b, c; i < n; i++)
    {
        cin >> A[i].num >> A[i].name >> A[i].score;
        sum += A[i].score;
    }
    sum /= n;
    printf("%.2lf\n", sum);
    for (int i = 0, a, b, c; i < n; i++)
    {
        if (A[i].score < sum)
            cout << A[i].name << " " << A[i].num << endl;
    }
    return 0;
}
