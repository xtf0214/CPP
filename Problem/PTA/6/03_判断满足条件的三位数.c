#include <stdio.h>
#include <math.h>

int search(int n);

int main()
{
    int number;

    scanf("%d", &number);
    printf("count=%d\n", search(number));

    return 0;
}

int search(int n)
{
    int num = 0;
    int A[10] = {0};
    for (int i = 10;; i++)
    {
        int t = i * i;
        if (t > n)
            break;
        if (t < 101)
            continue;
        int a = t % 10;
        t /= 10;
        int b = t % 10;
        t /= 10;
        int c = t % 10;
        if (a == b || a == c || b == c)
            num++;
    }
    return num;
}