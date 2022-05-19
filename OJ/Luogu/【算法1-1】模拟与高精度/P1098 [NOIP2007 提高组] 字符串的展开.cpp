#include <iostream>
#include <string>
using namespace std;
int p1, p2, p3;
string A;
int type(char x)
{
    if (x >= '0' && x <= '9')
        return 1;
    else if (x >= 'a' && x <= 'z')
        return -1;
    else
        return 0;
} //判断是否同一类型
void print(int x)
{
    if (p1 == 3)
        cout << "*"; //p1 = 3时，不论是字母子串还是数字字串，都用与要填充的字母个数相同的星号“*”来填充
    else if (type(x) == -1)
    {
        if (p1 == 1)
            cout << (char)(x); //p1=1时，对于字母子串，填充小写字母
        else if (p1 == 2)
            cout << (char)(x - 'a' + 'A'); //p1 = 2时，对于字母子串，填充大写字母
    }
    else if (type(x) == 1)
        if (p1 == 1 || p1 == 2)
            cout << (char)(x); //这两种情况下数字子串的填充方式相同
}
void Unfold(char a, char b)
{
    if (a == '-' || b == '-')
    {
        cout << "-";
        return;
    }
    if (type(a) == type(b))
    {

        if (a >= b) 
            cout << "-"; //如果减号右边的字符按照ASCII码的顺序小于或等于左边字符，输出时，要保留中间的减号
        else if (a + 1 == b)
            cout << ""; //减号右边的字符恰好是左边字符的后继，只删除中间的减号
        else
        {
            if (p3 == 1) 
                for (int i = a + 1; i < b; i++) //p3 = 1表示维持原来顺序
                    for (int j = 0; j < p2; j++) //p2 = k表示同一个字符要连续填充k个
                        print(i);
            else if (p3 == 2)
                for (int i = b - 1; i > a; i--) //p3 = 2表示采用逆序输出
                    for (int j = 0; j < p2; j++) //p2 = k表示同一个字符要连续填充k个
                        print(i);
        }
    }
    else
        cout << "-";
}
int main()
{
    cin >> p1 >> p2 >> p3;
    cin >> A;
    for (int i = 0; i < A.size(); i++)
    {
        if (i == 0 || i == A.size() - 1)
        {
            cout << A[i];
            continue;
        }
        if (A[i] == '-')
            Unfold(A[i - 1], A[i + 1]);
        else
            cout << A[i];
    }
    return 0;
}