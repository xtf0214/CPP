#include <stdio.h>
int main()
{
    int ans, n, x;
    scanf("%d%d", &ans, &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        if (x < 0)
        {
            printf("Game Over\n");
            return 0;
        }
        if (x > ans)
            printf("Too big\n");
        else if (x < ans)
            printf("Too small\n");
        else
        {
            if (i == 1)
                printf("Bingo!\n");
            else if (i <= 3)

                printf("Lucky You!\n");
            else
                printf("Good Guess!");
            return 0;
        }
    }
    if (scanf("%d", &x) == 1)
        printf("Game Over\n");
    return 0;
}