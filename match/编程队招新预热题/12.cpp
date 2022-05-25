#include <iostream>
#include <stack>
using namespace std;
const int INF = 0x3f3f3f3f;
int calc(int n2, char op, int n1)
{
    switch (op)
    {
    case '+':
        return n2 + n1;
        break;
    case '-':
        return n2 - n1;
        break;
    case '*':
        return n2 * n1;
        break;
    case '/':
        return n1 == 0 ? INF : n2 / n1;
        break;
    }
}
int main()
{
    stack<char> S2;
    stack<int> S1;
    int n, a;
    char c;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        S1.push(a);
    }
    for (int i = 0; i < n - 1; i++)
    {
        cin >> c;
        S2.push(c);
    }
    while (!S2.empty())
    {
        int n1 = S1.top();
        S1.pop();
        int n2 = S1.top();
        S1.pop();
        char op = S2.top();
        S2.pop();
        int ans = calc(n2, op, n1);
        if (ans == INF)
        {
            printf("ERROR: %d/0", n2);
            return 0;
        }
        S1.push(ans);
    }
    cout << S1.top();
    return 0;
}