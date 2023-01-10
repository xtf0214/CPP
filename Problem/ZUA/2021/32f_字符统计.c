#include <stdio.h>
#include <string.h>
int main()
{
    int a = 0, b = 0;
    char A[100];
    scanf("%s", A);
    for (int i = 0; i < strlen(A); i++)
    {
        if ('A' <= A[i] && A[i] <= 'Z' || 'a' <= A[i] && A[i] <= 'z')
            a++;
        else if ('0' <= A[i] && A[i] <= '9')
            b++;
    }
    printf("%d %d", a, b);
    return 0;
}