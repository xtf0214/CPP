#include <iostream>
#include <algorithm>
using namespace std;
struct Student
{
    int num, score;
    bool operator<(const Student &T) { return score < T.score; }
} student[10];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &student[i].num, &student[i].score);
    sort(student, student + n);
    for (int i = 0; i < n; i++)
        printf("%d %d\n", student[i].num, student[i].score);
    return 0;
}