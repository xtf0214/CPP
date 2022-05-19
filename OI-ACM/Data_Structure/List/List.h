#include <cstdio>
class List
{
private:
    struct Node
    {
        int key, se;
        Node *pNext;
    };
    Node *pFirst;
    int n;

public:
    List()
    {
        pFirst = new Node;
        *pFirst = {0, 0, NULL};
        n = 0;
    }

    /*从链表尾部插入值为key的新结点*/
    void push(int key)
    {
        Node *x = new Node;
        n++;
        x->key = key;
        x->pNext = pFirst->pNext;
        if (pFirst->pNext != NULL)
            x->se = pFirst->pNext->se + 1;
        pFirst->pNext = x;
    }

    /*删除链表内最后一个值为key的结点*/
    void pop(int key)
    {
        Node *p = pFirst->pNext; //指向最后一个节点
        while (p->pNext != NULL)
        {
            if (p->pNext->key == key)
            {
                p->pNext = p->pNext->pNext;
                n--;
                break;
            }
            p = p->pNext;
        }
        if (p->pNext == NULL)
            return; //未找到key
        Node *p1 = pFirst->pNext;
        while (p1 != p->pNext)
        {
            p1->se--, p1 = p1->pNext;
        }
    }

    /*逐个打印链表内所有结点*/
    void print()
    {
        Node *p = pFirst->pNext;
        while (p != NULL)
        {
            printf("[%d] = %d ", p->se, p->key);
            p = p->pNext;
        }
    }

    /*返回第i个结点的值*/
    int operator[](int i)
    {
        Node *p = pFirst->pNext;
        while (p->se != i)
            p = p->pNext;
        return p->key;
    }

    /*返回链表长度*/
    int size() { return n; }
};