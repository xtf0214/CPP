#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;
const int student_number = 8, university_number = 5, wishs_number = 3, q = 6;
struct Student
{
    int number, grade, accessd = -1;
} student[student_number];
struct University
{
    int number, admitted = -1, tail = 0;
    int freshfish[q];
    int score[q];
    void add(Student X)
    {
        freshfish[tail] = X.number;
        score[tail] = X.grade;
        tail++;
    }
    void print()
    {
        cout << number << "大学：" << endl;
        for (int i = 0; i <= tail - 1; i++)
        {
            int t = freshfish[i];
            cout << t << "分数:" << score[i] << endl;
            if (student[t].accessd == -1 && admitted == -1)
                student[t].accessd = number, admitted = t;
        }
        cout << endl;
    }
} university[university_number];
bool cmp(const University &a, const University &b)
{
    return a.score > b.score;
}
int main()
{
    srand(time(0));
    system("chcp 65001");
    for (int i = 0; i < student_number; i++)
    {
        student[i].number = i;
        cin >> student[i].grade;
        for (int j = 0, wish; j < wishs_number; j++)
        {
            cin >> wish;
            university[wish].add(student[i]);
        }
    } //填报志愿：姓名，成绩，志愿大学名单
    for (int i = 0; i < university_number; i++)
    {
        university[i].number = i;
        sort(university[i].freshfish, university[i].freshfish + university[i].tail);
    } //大学筛选考生
    for (int i = 0; i < university_number; i++)
        university[i].print(); //完成录取工作
    for (int i = 0; i < university_number; i++)
        cout << university[i].admitted << "被" << i << "大学录取" << endl;
    return 0;
}
