// 7-6 输入学生信息
#include <stdio.h>
struct Student
{
    int num, score;
} student[10];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &student[i].num, &student[i].score);
    for (int i = 0; i < n; i++)
        printf("%d %d\n", student[i].num, student[i].score);
    return 0;
}