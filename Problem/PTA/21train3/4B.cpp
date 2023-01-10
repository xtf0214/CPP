#include <bits/stdc++.h>
using namespace std;

bool isOP(char c) { return (c == '+' || c == '-' || c == '*' || c == '/'); }
void solve()
{
    stack<string> sl;
    stack<double> sr;
    string s;
    double a, b;
    char op;
    while (cin >> s)
        sl.push(s);
    while (!sl.empty())
    {
        // sl栈顶是运算符，直接运算
        if (sl.top().size() == 1 && isOP(sl.top()[0]))
        {
            // 可以运算
            if (sr.size() >= 2)
            {
                a = sr.top(), sr.pop();
                b = sr.top(), sr.pop();
                op = sl.top()[0], sl.pop();
                if (op == '+') sr.push(a + b);
                else if (op == '-') sr.push(a - b);
                else if (op == '*') sr.push(a * b);
                else if (b != 0) sr.push(a / b);
                else return void(cout << "ERROR");
            }
            // 表达式错误
            else return void(cout << "ERROR");
        }
        // sl栈顶是数字，移到sr中
        else sr.push(stod(sl.top())), sl.pop(); // stod()  c++11函数 string转double
    }
    // 表达式错误，数字多了
    if (sr.size() != 1)
        cout << "ERROR";
    else
        printf("%.1lf", sr.top());
}
int main()
{
    solve();
    return 0;
}