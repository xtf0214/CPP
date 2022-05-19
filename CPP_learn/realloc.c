#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *begin;
    int size;
} List;
void push_back(List *A, int x)
{
    int *t = (int *)realloc(A->begin, sizeof(int) * 2);
    A->begin = t;
    A->size++;
}
List A = {NULL, 0};
int main()
{
    // printf("%p,%d", A.begin, A.size);
    push_back(&A, 1);
    push_back(&A, 2);
    for (int i = 0; i < A.size; i++)
        printf("%d ", A.begin[i]);
    printf("%d", sizeof(int *));
}