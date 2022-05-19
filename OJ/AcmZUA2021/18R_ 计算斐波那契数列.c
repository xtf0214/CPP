#include <stdio.h>
int main()
{
    int n_1 = 1, n_2 = 1, n;
    printf("1 1 ");
    for (int i = 3; i <= 20; i++)
    {
        n = n_1 + n_2;
        printf("%d ", n);
        if (i % 5 == 0)
            printf("\n");
        n_2 = n_1;
        n_1 = n;
    }
    return 0;
}