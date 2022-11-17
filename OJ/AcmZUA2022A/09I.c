#include <stdio.h>

#include <stdlib.h>
struct node
{
    int x;
    struct node *next;
};

void insert_tail(struct node *H, int x)
{
    struct node *p, *t;
    t = (struct node *)malloc(sizeof(struct node));
    for (p = H; p->next != NULL; p = p->next)
        ;
    t->next = p->next;
    p->next = t;
    t->x = x;
}

void print(struct node *H)
{
    struct node *p;
    p = H->next;
    while (p != 0)
    {
        printf("%d ", p->x);
        p = p->next;
    }
}

void freeheadlist(struct node *h)
{
    struct node *t;
    h = h->next;
    while (h)
    {
        t = h->next;
        free(h);
        h = t;
    }
}
int main()
{
    struct node H;
    int x;
    int i;
    H.next = 0;

    for (i = 1; i <= 5; i++)
    {
        scanf("%d", &x);
        insert_tail(&H, x);
    }
    print(&H);
    freeheadlist(&H);
    return 0;
}