#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;
const int student_number = 8, university_number = 5, wishs_number = 3, q = 6;
struct Student
{
    int number, grade, accessd = -1, Wish[wishs_number];
} student[student_number];
struct University
{
    int number, admitted = -1, tail = 0;
    int freshfish[q];
    int score[q];
    void Sort()
    {
        for (int i = 1; i <= tail - 1; i++)
            for (int j = tail - 1; j >= i; j--)
                if (score[j] > score[j - 1])
                    swap(score[j], score[j - 1]),
                        swap(freshfish[j], freshfish[j - 1]);
    }
    void add(Student X)
    {
        freshfish[tail] = X.number;
        score[tail] = X.grade;
        tail++;
    }
    void print()
    {
        cout << char(number + 'A') << "大学：";
        for (int i = 0; i <= tail - 1; i++)
        {
            int t = freshfish[i];
            cout << char(t + 'a') << "分数:" << score[i] << "    ";
            if (student[t].accessd == -1 && admitted == -1)
            {
                student[t].accessd = number;
                admitted = t;
            }
        }
        cout << endl
             << endl;
    }
};

int main()
{
    srand(time(0));
    int A[5] = {0, 1, 2, 3, 4};
    system("chcp 65001");
    while (true)
    {
        University university[university_number];
        for (int i = 0; i < student_number; i++)
        {
            student[i].number = i;
            student[i].accessd = -1;
            student[i].grade = student_number - i;
            for (int k = university_number - 1; k >= 1; k--)
                swap(A[k], A[rand() % k]);
            for (int j = 0; j < wishs_number; j++)
            {
                student[i].Wish[j] = A[j];
                university[A[j]].add(student[i]);
            }
        } //填报志愿：姓名，成绩，志愿大学名单
        for (int i = 0; i < university_number; i++)
        {
            university[i].number = i;
            university[i].Sort();
        } //大学筛选考生
        for (int i = 0; i < student_number; i++)
        {
            cout << char(i + 'a') << "的志愿：";
            for (int j = 0; j < wishs_number; j++)
                cout << char(student[i].Wish[j] + 'A') << " ";
            cout << endl
                 << endl;
        }
        for (int i = 0; i < university_number; i++)
            university[i].print(); //完成录取工作
        for (int i = 0; i < university_number; i++)
            cout << char(university[i].admitted + 'a') << "被" << char(i + 'A') << "大学录取" << endl;
        system("pause");
    }
    return 0;
}
