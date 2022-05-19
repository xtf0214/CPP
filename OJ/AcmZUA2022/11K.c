#include <stdio.h>
#include <stdlib.h>
struct node
{
    int x;
    struct node *next;
};

void insert(struct node *H, int k)
{
    for (struct node *p = H;; p = p->next)
        if (p->next == NULL || p->next->x > k)
        {
            struct node *t = (struct node *)malloc(sizeof(struct node));
            t->next = p->next;
            p->next = t;
            t->x = k;
            break;
        }
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
    struct node H, *t, *tail;
    int x;
    int i;
    int p;

    H.next = 0;
    tail = &H;

    for (i = 1; i <= 4; i++)
    {
        scanf("%d", &x);
        t = (struct node *)malloc(sizeof(struct node));
        t->x = x;
        t->next = 0;

        tail->next = t;
        tail = t;
    }

    scanf("%d", &p);
    insert(&H, p);

    print(&H);
    freeheadlist(&H);
    return 0;
}