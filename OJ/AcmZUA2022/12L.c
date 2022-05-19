#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int key;
    struct Node *next;
} * head;
void push_back()
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    scanf("%d", &(t->key));
    t->next = NULL;
    for (struct Node *p = head;; p = p->next)
        if (p->next == NULL)
        {
            p->next = t;
            break;
        }
}
void del(int x)
{
    for (struct Node *p = head; p->next;)
        if (p->next->key == x)
            p->next = p->next->next;
        else
            p = p->next;
}
void print()
{
    for (struct Node *p = head->next; p; p = p->next)
        printf("%d\n", p->key);
}
int main()
{
    head = (struct Node *)malloc(sizeof(struct Node));
    head->next = NULL;
    int n, m;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        push_back();
    scanf("%d", &m);
    del(m);
    print();
    return 0;
}