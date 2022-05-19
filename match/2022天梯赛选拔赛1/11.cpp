#include <iostream>
#include <algorithm>
using namespace std;
int n, k;
struct Lesson
{
    int a, b;
} les[100];
bool cmp(const Lesson &A, const Lesson &B) { return A.b < B.b; }
int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> les[i].a >> les[i].b;
    sort(les, les + k, cmp);
    
}