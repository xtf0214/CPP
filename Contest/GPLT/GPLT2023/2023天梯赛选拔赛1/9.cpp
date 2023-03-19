#include <iostream>
#include <stack>
using namespace std;

int n, m, k;
int x[1005];
bool solve() {
    int st = 1;
    stack<int> s;
    for (int i = 0; i < n; i++)
        cin >> x[i];
    for (int i = 0; i < n; i++) {
        if (x[i] != st)
            s.push(x[i]);
        else
            st++;
        if (s.size() > m)
            return false;
        while (!s.empty() && s.top() == st) {
            st++;
            s.pop();
        }
    }
    return s.empty();
}
int main() {
    cin >> n >> m >> k;
    while (k--)
        puts(solve() ? "YES" : "NO");
}