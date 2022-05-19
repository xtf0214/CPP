#include <stdio.h>
int main()
{
    int A[10] = {0, 1, 2, 3, 4, 3, 2, 1};
    for (int i = 1; i <= 7; i++)
    {
        for (int j = 1; j <= 6 - A[i]; j++)
            printf(" ");
        for (int j = 1; j <= 2 * A[i] - 1; j++)
            printf("*");
        printf("\n");
    }
    return 0;
}