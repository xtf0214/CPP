#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof(struct STUDENT)
struct STUDENT
{
    long num;
    float score;
    struct STUDENT *next;
};
int n;
void print(struct STUDENT *head)
{
    for (struct STUDENT *p = head; p; p = p->next)
        printf("%ld %f\n", p->num, p->score);
}
struct STUDENT *creat()
{
    struct STUDENT *head, *p1, *p2;
    n = 0;
    p1 = p2 = (struct STUDENT *)malloc(LEN);
    scanf("%ld%f", &p1->num, &p1->score);
    head = NULL;
    while (p1->num != 0)
    {

        n = n + 1;
        if (n == 1)
            head = p1;
        else
            p2->next = p1;
        p2 = p1;
        p1 = (struct STUDENT *)malloc(LEN);
        scanf("%ld%f", &p1->num, &p1->score);
    }
    p2->next = NULL;
    free(p1);
    return (head);
}
void freenoheadlist(struct STUDENT *h)
{
    struct STUDENT *t;
    while (h)
    {
        t = h->next;
        free(h);
        h = t;
    }
}
int main()
{
    struct STUDENT *pt;
    pt = creat();
    print(pt);
    freenoheadlist(pt);
    return 0;
}