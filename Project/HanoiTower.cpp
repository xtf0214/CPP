#include <iostream>
using namespace std;
void hanoi(int n, char from, char mid, char to)
{
    if (n == 0)
        return;
    hanoi(n - 1, from, to, mid);
    printf("%d: %c -> %c\n", n, from, to);
    hanoi(n - 1, mid, from, to);
}
int main()
{
    int n;
    char from, mid, to;
    cin >> n >> from >> to >> mid;
    hanoi(n, from, mid, to);
    return 0;
}