#include <cstdio>
using namespace std;
int main()
{
    int x;
    float y = 0;
    scanf("%d", &x);
    if (x >= 0 && x <= 150)
        y = 0.4463 * x;
    if (x > 150 && x <= 400)
        y = 150 * 0.4463 + (x - 150) * 0.4663;
    if (x > 400)
        y = 150 * 0.4463 + 250 * 0.4663 + (x - 400) * 0.5663;
    printf("%.1f", y);
    return 0;
}