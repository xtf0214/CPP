#include <iostream>
using DateType = int;
using namespace std;
struct Node
{
    DateType val;
    Node *next;
    Node(DateType _val, Node *_next) : val(_val), next(_next) {}
};
struct List
{
    Node *head;
    List() { head = new Node(0, NULL); }
    void insert(DateType key, int pos)
    {
        for (Node *p = head->next; p; p = p->next)
            if (p->val == pos)
            {
                Node *t = new Node(key, p->next);
                p->next = t;
                head->val++;
                break;
            }
    }
    // 删除第一个值为key的结点
    void erase(DateType key)
    {
        for (Node *p = head, *t; p->next; p = p->next)
            if (p->next->val == key)
            {
                t = p->next;
                p->next = p->next->next;
                head->val--;
                delete t;
                break;
            }
    }
    Node *search(DateType key)
    {
        for (Node *p = head->next; p; p = p->next)
            if (p->val == key)
                return p->next;
        return NULL;
    }
    void print()
    {
        for (Node *p = head->next; p; p = p->next)
            printf("%d ", p->val);
    }
    void merge(List &ls)
    {
        Node *p;
        for (p = head; p->next; p = p->next)
            ;
        p->next = ls.head->next;
        *(ls.head) = Node(0, NULL);
    }
    int size() { return head->val; }
};