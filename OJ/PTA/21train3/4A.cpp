#include <bits/stdc++.h>
using namespace std;
const double INF = 0x3f3f3f3f;
class Node
{
public:
    double num = INF;
    char op = 0;
    Node(double _num) { num = _num; }
    Node(char _op) { op = _op; }
    bool isOP() { return op != 0; }
};
double calc(double a, char op, double b)
{
    double arr[]{a + b, a - b, a * b, a / b};

    if (op == '+')
        return a + b;
    else if (op == '-')
        return a - b;
    else if (op == '*')
        return a * b;
    else if (b != 0)
        return a / b;
    else
        return INF;
}
bool isOP(char c) { return (c == '+' || c == '-' || c == '*' || c == '/'); }
void solve()
{
    string s;
    stack<Node> sl;
    stack<double> sr;
    double a, b, ans;
    char op;
    while (cin >> s)
        isOP(s[0]) && s.size() == 1 ? sl.push(s[0]) : sl.push(stod(s));
    if (sl.size() < 3)
        sl.push(0.0);
    while (!sl.empty())
    {
        if (!sl.top().isOP())
            sr.push(sl.top().num), sl.pop();
        else if (sr.size() >= 2)
        {
            a = sr.top(), sr.pop();
            b = sr.top(), sr.pop();
            op = sl.top().op, sl.pop();
            ans = calc(a, op, b);
            if (ans == INF)
                return void(cout << "ERROR");
            sr.push(ans);
        }
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