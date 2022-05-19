#include <stdio.h>
#include <string.h>
int main()
{
    int A[30], l = 0;
    for (int i = 0; i < 26; i++)
        A[i] = 0;
    char B[85], C[30];
    scanf("%[^\n]", B);
    for (int i = 0; i < strlen(B); i++)
        if (B[i] >= 'A' && B[i] <= 'Z')
            if (A[B[i] - 'A'] == 0)
            {
                C[l++] = B[i];
                A[B[i] - 'A'] = 1;
            }
    for (int i = 0; i < l; i++)
        printf("%c", C[i]);
    if (l == 0)
        printf("Not Found");
    return 0;
}