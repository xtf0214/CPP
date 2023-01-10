#include <iostream>
using namespace std;
void dfs(int n, char from, char to)
{
    if (n == 1)
    {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }
    char mid = 'A' + 'B' + 'C' - from - to;
    dfs(n - 1, from, mid);
    printf("Move disk %d from %c to %c\n", n, from, to);
    dfs(n - 1, mid, to);
}
int main()
{
    int n;
    cin >> n;
    dfs(n, 'A', 'C');
    return 0;
}