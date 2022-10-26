#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int key;
    Node *prev, *next;
};
class List
{
private:
    Node *head, *tail;

public:
    List()
    {
        head = new Node, tail = new Node;
        head->next = tail;
        tail->prev = head;
        head->prev = tail->next = NULL;
    }
    void remove(int x)
    {
        for (Node *p = head->next; p != tail; p = p->next)
            if (p->key == x)
            {
                p->prev->next = p->next;
                p->next->prev = p->prev;
            }
    }
    void push_back(int x)
    {
        Node *node = new Node;
        node->key = x;
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }
    void insert(int id, int x, int locate)
    {
        Node *node = new Node;
        node->key = x;
        for (Node *p = head->next; p != tail; p = p->next)
            if (p->key == id)
                if (locate == 0)
                {
                    node->next = p;
                    node->prev = p->prev;
                    p->prev->next = node;
                    p->prev = node;
                }
                else if (locate == 1)
                {
                    node->prev = p;
                    node->next = p->next;
                    p->next->prev = node;
                    p->next = node;
                }
    }
    void print()
    {
        for (Node *p = head->next; p != tail; p = p->next)
            cout << p->key << " ";
    }
};
int main()
{
    List A;
    int n, m;
    cin >> n;
    A.push_back(1);
    for (int i = 2, id, locate; i <= n; i++)
    {
        scanf("%d %d", &id, &locate);
        A.insert(id, i, locate);
    }
    cin >> m;
    for (int i = 0, id; i < m; i++)
    {
        scanf("%d", &id);
        A.remove(id);
    }
    A.print();
    return 0;
}